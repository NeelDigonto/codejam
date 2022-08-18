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
constexpr static const char* pName = "Reversort";

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
using std::vector;

template <typename FType>
void loop(FType _callback, sz _ntimes)
{
    for (sz iter = 0; iter != _ntimes; ++iter)
        _callback(iter);
}

void sandbox();

int main()
{

    std::ifstream input_file;
    std::ofstream output_file;

    if constexpr (IS_LOCAL)
    {
        input_file.open("files/Reversort/i1.txt");
        if (!input_file.is_open())
            std::cout << "Couldn't open input file.";
        std::cin.rdbuf(input_file.rdbuf());

        //std::filesystem::create_directories("files/Reversort");
        output_file.open("files\\Reversort\\r1.txt");
        if (!output_file.is_open())
            std::cout << "Couldn't open output file.";

        std::cout.rdbuf(output_file.rdbuf());
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

auto Reversort(vector<u32> _c)
{
    sz cost = 0;
    for (auto it = _c.begin(); it != _c.end() - 1; ++it)
    {
        auto min = std::min_element(it, _c.end());
        cost += std::distance(it, min + 1);
        std::reverse(it, min + 1);
    }

    return cost;
}

void sandbox()
{
    sz test_cases;
    cin >> test_cases;

    vector<u32> vec;
    vec.reserve(100);

    loop([&vec](sz csno)
        {
            sz N;
            cin >> N;

            loop([&vec](sz i) {

                u32 temp;
                cin >> temp;
                vec.push_back(temp);

                }, N);
            cout << "Case #" << csno + 1 << ": " << Reversort(vec) << std::endl;
            vec.clear(); },
        test_cases);
}
