#pragma once
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

std::ifstream input_file;
std::ofstream output_file;
std::streambuf* _cinbuf; //save old buf
std::streambuf* _coutbuf; //save old buf
std::streambuf* cinbuf; //save old buf
std::streambuf* coutbuf; //save old buf

template<typename First, typename Second>
constexpr auto swapbuff(First a, Second b) -> std::enable_if_t<std::is_same_v<First, Second>, void> {
    First temp = a;
    a = b;
    b = temp;
}

constexpr void swapcinbuff() {
    swapbuff(_cinbuf, cinbuf);
    std::cin.rdbuf(cinbuf);
}

constexpr void swapcoutbuff() {
    swapbuff(_coutbuf, coutbuf);
    std::cin.rdbuf(coutbuf);
}

int main()
{

    if constexpr (IS_LOCAL)
    {
        _cinbuf = std::cin.rdbuf(); //save old buf
        _coutbuf = std::cout.rdbuf(); //save old buf

        input_file.open("files\\CheatingDetection\\test_set_2\\ts2_input.txt");
        if (!input_file.is_open())
            std::cout << "Couldn't open input file.";
        std::cin.rdbuf(input_file.rdbuf());

        //std::filesystem::create_directories("files\\r1.txt");
        output_file.open("files\\CheatingDetection\\r_ts2.txt");
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

void sandbox()
{
    sz test_cases;
    cin >> test_cases;

    constexpr static sz players = 100;
    constexpr static sz questions = 10'000;

    loop([](sz csno)
        {
            sz P;
            cin >> P;



        }, test_cases);

}

