#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>


bool is_beautiful(int h, int m) {
    std::string hs = (h < 10 ? "0" : "") + std::to_string(h);
    std::string ms = (m < 10 ? "0" : "") + std::to_string(m);

    if (h == m) {
        return true;
    }

    std::string reversed_h_str = hs;
    std::reverse(reversed_h_str.begin(), reversed_h_str.end());
    if (ms == reversed_h_str) {
        return true;
    }

    std::string time_str = hs + ms;
    if (time_str.length() == 4) {
        bool is_consecutive = true;
        for (size_t i = 0; i < 3; ++i) {
            if (time_str[i+1] != time_str[i] + 1) {
                is_consecutive = false;
                break;
            }
        }
        if (is_consecutive) {
            return true;
        }
    }

    return false;
}


int main() {
    int h1, m1, h2, m2;

    std::cin >> h1 >> m1 >> h2 >> m2;

    int count = 0;
    int hc = h1;
    int mc = m1;

    while (true) {
        if (is_beautiful(hc, mc)) {
            count++;
        }

        if (hc == h2 && mc == m2) {
            break;
        }

        mc++;
        if (mc == 60) {
            mc = 0;
            hc = (hc + 1) % 24;
        }
    }

    std::cout << count << std::endl;
}