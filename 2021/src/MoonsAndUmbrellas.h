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
constexpr static const char* pName = "MoonsAndUmbrellas";

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

void sandbox();

int main()
{

    std::ifstream input_file;
    std::ofstream output_file;

    if constexpr (IS_LOCAL)
    {
        input_file.open("files/MoonsAndUmbrellas/i1.txt");
        if (!input_file.is_open())
            std::cout << "Couldn't open input file.";
        std::cin.rdbuf(input_file.rdbuf());

        //std::filesystem::create_directories("files\\r1.txt");
        output_file.open("files\\MoonsAndUmbrellas\\r1.txt");
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


u32 X, Y;
string S;

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

template<typename T, typename Iter>
auto getCost(const T& _str, Iter _start, Iter _end)
-> std::enable_if_t<std::is_same_v<typename T::value_type, char>, char> {

    sz cost = 0;
    if (_start != _str.begin() && _end != _str.end()) {
        Iter left = _start - 1, right = _end;

        if (*left == 'C' && *right == 'C' || *left == 'J' && *right == 'J') {
            return 0;
        }
        else if (*left == 'C') {
            return X;
        }
        else /*if (*left == 'J')*/ {
            return Y;
        }
    }
    else return 0;

}

void sandbox()
{
    sz test_cases;
    cin >> test_cases;

    loop([](sz csno)
        {
            
            cin >> X >> Y >> S;

            sz cost = 0;
            auto left = S.begin();

            cost += countSubstring(S, "CJ") * X;
            cost += countSubstring(S, "JC") * Y;

            if (S.size() != 1 && S.size() != 2)
                while (left < S.end()) {

                    if (*left != '?') left++;
                    else {
                        auto right = left + 1;

                        while (right != S.end() && *right == '?') right++;

                        cost += getCost(S, left, right);

                        left = right;
                    }

                }

            cout << "Case #" << csno + 1 << ": " << cost << "\n";

            cost = 0;

        }, test_cases);

}

