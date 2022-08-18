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
constexpr static const char* pName = "A";

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
        input_file.open("files/A/i1.txt");
        if (!input_file.is_open())
            std::cout << "Couldn't open input file.";
        std::cin.rdbuf(input_file.rdbuf());
    }
    else
    {
        //std::ios_base::sync_with_stdio(0);
        //std::cin.tie(0);
        //std::cout.tie(0);
    }

    sandbox();

    return 0;
}


void sandbox()
{
    sz test_cases;
    cin >> test_cases;

    for (sz csno{ 0 }; csno != test_cases; csno++) {
        sz R, C;
        cin >> R >> C;

        const sz card_rows = 2 * R + 1;
        const sz card_cols = 2 * C + 1;

        vector<vector<char>> card(card_rows, vector<char>());

        card[0].insert(card[0].begin(), { '.', '.' });
        card[1].insert(card[1].begin(), { '.', '.' });

        for (sz row = 0; row < card_rows; row++) {
            for (sz col = 0; col < card_cols - 2; col += 2) {
                if (row == 0 || row == 1)
                    if (col == 0 || col == 1)
                        continue;

                if (row % 2 == 0)
                    card[row].insert(card[row].end(), { '+', '-' });
                else
                    card[row].insert(card[row].end(), { '|', '.' });
            }
            if (row % 2 == 0)
                card[row].emplace_back('+');
            else
                card[row].emplace_back('|');
        }

        cout << "Case #" << csno + 1 << ": \n";

        for (auto& vec : card)
        {
            for (auto& ch : vec)
                cout << ch;
            cout << '\n';
        }

    }
}

