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
            uint64_t p_del_sn = 0; n_del_sn = 0;
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