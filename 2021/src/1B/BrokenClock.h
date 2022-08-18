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

#include <memory>
#include <memory_resource>
#include <scoped_allocator>
#include <climits>
#include <limits>

#include <cassert>
#include <exception>
#include <stdexcept>

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
#include <execution>

#include <cmath>
#include <complex>
#include <random>
#include <ratio>

#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <sstream>
#include <streambuf>

#include <filesystem>

#include <regex>

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

        sz N;
        u32 A, B;

        vector<u32> metals;
        metals.reserve(N);

        cin >> N >> A >> B;

        loop([&metals]() {
            u32 in;
            cin >> in;
            metals.push_back(in);
            }, N);



    }
    

}

