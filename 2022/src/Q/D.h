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
constexpr static const char* pName = "D";

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
        input_file.open("files/D/i1.txt");
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

struct Node {
    u32 id;
    u64 fun;
    forward_list<Node> childs;
    Node() = default;
};

u64 total_fun = 0;

u64 calcFun(Node& _node);

void sandbox()
{
    sz test_cases;
    cin >> test_cases;

    for (sz csno{ 0 }; csno != test_cases; csno++) {
        sz N;
        cin >> N;

        vector<u32> funs;
        funs.reserve(N);

        loop([&funs](sz _) {
            u64 fun;
            cin >> fun;
            funs.push_back(fun);
            }, N);

        forward_list<Node> roots; // these points to abycess
        unordered_map<u32, Node&> cache;
        cache.reserve(N);

        loop([&roots, &funs, &cache](sz v1) {

            u32 v2;
            cin >> v2;

            if (v2 == 0) {
                auto& iter = roots.emplace_front(Node{ static_cast<u32>(v1), funs[v1], {} });
                cache.insert({ v1, iter});
            }
            else {
                v2 -= 1;

                auto loc = cache.find(v2);
                if constexpr (IS_LOCAL) if (loc == cache.end()) cout << "SCAMMED";

                auto& iter = loc->second.childs.emplace_front(Node{ static_cast<u32>(v1), funs[v1], {} });
                cache.insert({ v1, iter });
            }

            }, N);

        funs.clear();
        cache.clear();


        for (auto root : roots) {
            total_fun += calcFun(root);
        }

        cout << "Case #" << csno + 1 << ": " << total_fun << "\n";
        total_fun = 0;
    }

}

u64 calcFun(Node& _node) {
    if (_node.childs.empty())
        return _node.fun;

    vector<u64> res;
    for (auto& child : _node.childs) {
        res.push_back(calcFun(child));
    }

    auto min = std::min_element(res.begin(), res.end());

    for (auto it = res.begin(); it != res.end(); it++) {
        if (it != min)
            total_fun += *it;
    }


    _node.fun = std::max(_node.fun, *min);

    return _node.fun;
}