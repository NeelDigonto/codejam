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
#include <optional>

constexpr static bool IS_LOCAL = false;
constexpr static const char* pName = "E";

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

struct Room{
    u32 room_id;
    u32 pssg_unex;
    unordered_set<u32> pssgto;
};

void sandbox()
{
    sz test_cases;
    cin >> test_cases;

    for (sz csno{ 0 }; csno != test_cases; csno++) {

        u32 N, K;
        cin >> N >> K;

        vector<optional<Room>> adj_list(N, std::nullopt);
        unordered_set<u32> to_teleports;

        loop([&to_teleports](sz i) {
            to_teleports.insert(i);
            }, N);

        u32 room_no, passg_nos;
        cin >> room_no >> passg_nos;
        room_no--;

        adj_list[room_no] = std::move(Room{ room_no, passg_nos, {} });
        to_teleports.erase(room_no);

        u32 interact_no{ 1 };

        // W   --> R P
        // T S --> R P
        // E P

        while (K + 1 - interact_no >= 2 && !to_teleports.empty()) {
            u32 total_passg = 0;

            //teleport there
            cout << "T " << *(to_teleports.begin()) + 1 << endl;
            cin >> room_no >> passg_nos;
            room_no--;

            to_teleports.erase(to_teleports.begin());
            adj_list[room_no] = std::move(Room{ room_no, passg_nos, {} });

            // now walk a path
            cout << "W" << endl;
            u32 prev_room = room_no;
            cin >> room_no >> passg_nos;
            room_no--;

            adj_list[prev_room].value().pssgto.insert(room_no);
            adj_list[prev_room].value().pssg_unex--;

            if (to_teleports.find(room_no) != to_teleports.end()) { // if in tp, then not in adj-list

                adj_list[room_no] = std::move(Room{ room_no, --passg_nos, {prev_room} });
                to_teleports.erase(room_no);
            }
            else if(adj_list[room_no].value().pssgto.find(prev_room) != adj_list[room_no].value().pssgto.end()) {

                adj_list[room_no].value().pssgto.insert(prev_room);
                adj_list[room_no].value().pssg_unex--;
            }

            interact_no += 2;
        }

        to_teleports.clear();

        /*while (K + 1 - interact_no != 0) {
            cout << "LOLOLOLOL";
            interact_no++;
        }*/

        // estimate and print result
        u64 total_passg = 0;
        for (auto& room : adj_list) {
            if (room.has_value())
                total_passg += room.value().pssg_unex + room.value().pssgto.size();
        }

        cout << "E " << total_passg << endl;

    }

}