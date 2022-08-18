#pragma once
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <filesystem>
#include <chrono>
#include <memory>

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <bitset>
#include <complex>
#include <random>

#include <array>
#include <vector>
#include <list>
#include <tuple>
#include <forward_list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

constexpr static bool IS_LOCAL = true;
constexpr static const char* pName = "B";

using sz = std::size_t;
using i16 = std::int16_t;
using u16 = std::uint16_t;
using i32 = std::int32_t;
using u32 = std::uint32_t;
using i64 = std::int64_t;
using u64 = std::uint64_t;

using std::array;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using namespace std;

template <typename FType>
void loop(FType _callback, sz _ntimes)
{
    for (sz iter = 0; iter != _ntimes; ++iter)
        _callback(iter);
}

std::size_t countSubstring(const std::string& str, const std::string& sub)
{
    if (sub.length() == 0) return 0;
    std::size_t count = 0;
    for (size_t offset = str.find(sub); offset != std::string::npos;
        offset = str.find(sub, offset + sub.length()))
    {
        ++count;
    }
    return count;
}

void sandbox();

int main()
{

    std::ifstream input_file;
    std::ofstream output_file;

    if constexpr (IS_LOCAL)
    {
        input_file.open("files/B/i1.txt");
        if (!input_file.is_open())
            std::cout << "Couldn't open input file.";
        std::cin.rdbuf(input_file.rdbuf());
    }
    else
    {
        std::ios_base::sync_with_stdio(0);
        std::cin.tie(0);
        std::cout.tie(0);
    }

    sandbox();

    return 0;
}


void sandbox()
{
    sz test_cases;
    cin >> test_cases;

    for (sz csno{ 0 }; csno != test_cases; csno++) {
        array<array<u32, 3>, 4> tank; // rows --> colors  cols --> printer tank[color][printer]

        loop([&tank](sz lno) {
            cin >> tank[0][lno] >> tank[1][lno] >> tank[2][lno] >> tank[3][lno];
            }, 3);

        array<u32, 4> prt_min;

        prt_min[0] = *std::min_element(tank[0].begin(), tank[0].end());
        prt_min[1] = *std::min_element(tank[1].begin(), tank[1].end());
        prt_min[2] = *std::min_element(tank[2].begin(), tank[2].end());
        prt_min[3] = *std::min_element(tank[3].begin(), tank[3].end());


        cout << "Case #" << csno + 1 << ": ";

        auto sum = prt_min[0] + prt_min[1] + prt_min[2] + prt_min[3];
        if (sum < 1'000'000)
            cout << "IMPOSSIBLE";
        else
        {
            auto diff = sum - 1'000'000;

            for (auto it = prt_min.begin(); it != prt_min.end(); ++it) {
                *it -= std::min(*it, diff);

                sum = prt_min[0] + prt_min[1] + prt_min[2] + prt_min[3];
                diff = sum - 1'000'000;
            }

            cout << prt_min[0] << " " << prt_min[1] << " " << prt_min[2] << " " << prt_min[3];
        }
          
        cout << "\n";
    }
}

