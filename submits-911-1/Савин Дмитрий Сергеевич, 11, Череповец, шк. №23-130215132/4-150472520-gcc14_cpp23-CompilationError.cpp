#include <bits/stdc++.h>
#include <vector>

inline std::vector<uint64_t> GetGreatNumbers() noexcept {
    std::vector<uint64_t> great_nums {2};
    great_nums.reserve(100);
    for (uint64_t n = 3; n < 10'000; n += 2) {
        bool is_great = true;
        for (const auto& great_num : great_nums) {
            if (n % great_num == 0) {
                is_great = false;
                break;
            }
        }
        if (is_great)
            great_nums.push_back(n);
    }
    return great_nums;
}

int main() {
    static const auto great_nums = GetGreatNumbers();
    uint64_t n, k;
    std::cin >> n >> k;

    uint64_t result, result_reason = 0;
    for (uint64_t p = n+1; p < n+k; ++p) {
        std::vector<uint64_t> current_reason_parts;
        for (const auto& great_num : great_nums) {
            uint64_t p_del = 0, n_del = 0;
            uint64_t temp_p = p, temp_n = n;
            while (temp_p % great_num == 0) {
                temp_p /= great_num;
                p_del++;
            }
            while (temp_n % great_num == 0) {
                temp_n /= great_num;
                n_del++;
            }
            for (uint64_t i=0; i<std::max(p_del, n_del); ++i) 
                current_reason_parts.push_back(sn);
        }
        uint_64_t current_reason = 1;
        for (const auto& crp : current_reason_parts) 
            current_reason *= crp;
        if (result_reason > current_reason) {
            result = p;
            result_reason = current_reason;
        }
    }
    std::cout << result << std::endl;
    return 0;
}