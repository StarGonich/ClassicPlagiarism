#include <bits/stdc++.h>
#include <vector>

inline std::vector<uint64_t> GetSimpleNums() noexcept {
    std::vector<uint64_t> simple_nums;
    nums.reserve(200);
    for (uint64_t n = 2; n < 10'000; ++n) {
        bool result = true;
        for (const auto& sn : simple_nums) {
            if (n % sn == 0) {
                result = false;
                break;
            }
        }
        if (result)
            simple_nums.push_back(n);
    }
    return simple_nums;
}

int main() {
    uint64_t n, k;
    std::cin >> n >> k;

    const std::vector<uint64_t> simple_nums = GetSimpleNums();
    
    uint64_t result, result_obsh_num = 0;
    std::vector<uint64_t> kratn_nums;
    kratn_nums.reserve(100);
    for (uint64_t p = n+1; p <= n+k; ++p) {
        kratn_nums.clear();
        for (const auto& sn : simple_nums) {
            uint64_t p_del_sn = 0, n_del_sn = 0;
            uint64_t temp_p = p, temp_n = n;
            while (temp_p % sn == 0) {
                temp_p /= sn;
                p_del_sn++;
            }
            while (temp_n % sn == 0) {
                temp_n /= sn;
                n_del_sn++;
            }
            for (uint64_t i=0; i<std::max(p_del_sn, n_del_sn); ++i) 
                kratn_nums.push_back(sn);
        }
        uint64_t obsh_num = 1;
        for (const auto& mn : kratn_nums) {
            obsh_num *= mn;
        }
        if (obsh_num > result_obsh_num) {
            result = p;
            result_obsh_num = obsh_num;
        }
    }
    std::cout << result << std::endl;
    return 0;
}






/*



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
            while (cursor > 0) {
                --cursor;
                if (Ns.at(i).first < cursor + 3600)
                    length = std::min(Ns.at(i).second, cursor + 3600) - Ns.at(i).first;
                for (int64_t j = i - 1; j >= 0 && Ns.at(j).second > cursor; --j) {
                    length += std::min(Ns.at(j).second, cursor + 3600) - std::max(Ns.at(j).first, cursor);
                }
                if (length <= T)
                    break;
            }
            if (cursor != 0)
                ++cursor;
            break;
        }

        cursor = Ns.at(i).first;
        length = std::min(Ns.at(i).second, cursor + 3600) - Ns.at(i).first;
        for (int64_t j = i + 1; j < N && Ns.at(j).first < cursor + 3600; ++j) {
            length += std::min(Ns.at(j).second, cursor + 3600) - Ns.at(j).first; 
        }
        if (length > T) {
            while (cursor > 0) {
                --cursor;
                if (Ns.at(i).first < cursor + 3600) 
                    length = std::min(Ns.at(i).second, cursor + 3600) - Ns.at(i).first;
                for (int64_t j = i + 1; j < N && Ns.at(j).first < cursor + 3600; ++j) {
                    length += std::min(Ns.at(j).second, cursor + 3600) - Ns.at(j).first; 
                }
                if (length <= T)
                    break;
            }
            if (cursor != 0)
                ++cursor;
            break;
        }
    }
    std::cout << cursor << std::endl;
    return 0;
}