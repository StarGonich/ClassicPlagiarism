#include <bits/stdc++.h>
#include <vector>
#include <utility>

int main() {
    uint64_t N, T;
    std::cin >> N >> T;

    std::vector<std::pair<uint64_t, uint64_t>> Ns(N);
    for (uint64_t i = 0; i < N; ++i) 
        std::cin >> Ns[i].first >> Ns[i].second;

    uint64_t cursor = 0;
    for (int64_t i = 1, length = 0; i < N; ++i) {
        cursor = Ns.at(i).second - 3600;
        length = Ns.at(i).second - std::max(Ns.at(i).first, cursor);
        for (int64_t j = i - 1; j >= 0 && Ns.at(j).second > cursor; --j) {
            length += Ns.at(j).second - std::max(Ns.at(j).first, cursor);
        }
        if (length > T) {
            while (true) {
                --cursor;
                if (Ns.at(i).first < cursor + 3600)
                    length = std::min(Ns.at(i).second, cursor + 3600) - Ns.at(i).first;
                for (int64_t j = i - 1; j >= 0 && Ns.at(j).second > cursor; --j) {
                    length += std::min(Ns.at(j).second, cursor + 3600) - std::max(Ns.at(j).first, cursor);
                }
                if (length <= T)
                    break;
            }
            ++cursor;
            break;
        }

        cursor = Ns.at(i).first;
        length = std::min(Ns.at(i).second, cursor + 3600) - Ns.at(i).first;
        for (int64_t j = i + 1; j < N && Ns.at(j).first < cursor + 3600; ++j) {
            length += std::min(Ns.at(j).second, cursor + 3600) - Ns.at(j).first; 
        }
        if (length > T) {
            while (true) {
                --cursor;
                if (Ns.at(i).first < cursor + 3600) 
                    length = std::min(Ns.at(i).second, cursor + 3600) - Ns.at(i).first;
                for (int64_t j = i + 1; j < N && Ns.at(j).first < cursor + 3600; ++j) {
                    length += std::min(Ns.at(j).second, cursor + 3600) - Ns.at(j).first; 
                }
                if (length <= T)
                    break;
            }
            ++cursor;
            break;
        }
    }
    std::cout << cursor << std::endl;
    return 0;
}