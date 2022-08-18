//#pragma once
constexpr static bool IS_LOCAL = true;
constexpr static const char* pName = "A";

#include <any>
#include <bitset>
#include <chrono>
#include <cstdarg>
#include <cstddef>
#include <cstdlib>
#include <functional>
#include <initializer_list>
#include <optional> 
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <typeinfo>
#include <utility>
#include <variant>

#include <climits>
#include <limits>


#include <string>
#include <string_view>

#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <iterator>

#include <algorithm>



#include <cmath>
#include <complex>
#include <random>


#include <fstream>

#include <ios>
#include <iostream>
#include <sstream>


#include <filesystem>

using sz = std::size_t;
using i16 = std::int16_t;
using u16 = std::uint16_t;
using i32 = std::int32_t;
using u32 = std::uint32_t;
using i64 = std::int64_t;
using u64 = std::uint64_t;
using u8 = std::uint8_t;

using std::string;
using std::array;
using std::deque;
using std::forward_list;
using std::list;
using std::map;
using std::queue;
using std::set;
using std::stack;
using std::unordered_map;
using std::unordered_set;
using std::vector;

using std::cout;
using std::cin;
using std::endl;

//using namespace std;

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
        input_file.open("files/1B/B/s1.txt");
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
        u8 ones;

        u8 a0 = 0b00'00'00; // 0b11'11'11
        u8 a0 = 0b11'11'11;

        cout << a0;

        cin >> ones;


    }


}

