#include <bits/stdc++.h>
#include <vector>
#include <utility>

int main() {
    uint32_t N, T;
    std::cin >> N >> T;

    std::vector<std::pair<uint32_t, uint32_t>> Ns(N);
    for (uint32_t i = 0; i < N; ++i) 
        std::cin >> Ns[i].first >> Ns[i].second;

    uint32_t cursor = 0;
    for (uint32_t i = 0, length = 0; i < N; ++i) {
        cursor = Ns.at(i).second - 3600;
        length = Ns.at(i).second - Ns.at(i).first;
        for (uint32_t j = 0; j < i; ++j) {
            if (Ns.at(j).second > cursor)
                length += Ns.at(j).second - std::max(Ns.at(j).first, cursor);
        }
        if (length > T) {
            while (true) {
                --cursor;
                for (uint32_t j = 0; j < i; ++j) {
                    if (Ns.at(j).second > cursor)
                        length += Ns.at(j).second - std::max(Ns.at(j).first, cursor);
                }
                if (length == T)
                    break;
            }
            ++cursor;
            break;
        }

        cursor = Ns.at(i).first;
        length = Ns.at(i).second - Ns.at(i).first;
        for (uint32_t j = i + 1; j < N && Ns.at(j).first < cursor; ++j) {
            length += std::min(Ns.at(j).second, cursor) - Ns.at(j).first; 
        }
        if (length > T) {
            while (true) {
                --cursor;
                for (uint32_t j = i + 1; j < N && Ns.at(j).first < cursor; ++j) {
                    length += std::min(Ns.at(j).second, cursor) - Ns.at(j).first; 
                }
                if (length == T)
                    break;
            }
            ++cursor;
            break;
        }
    }
    std::cout << cursor << std::endl;
    return 0;
}