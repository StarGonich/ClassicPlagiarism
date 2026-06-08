#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int main() {
    int n;
    cin >> n;

    while (true) {
        vector <int> nums;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            nums.push_back(1 + rand() % 1000);
            sum += nums.back() * nums.back();
        }
        int sq = sqrt(sum);
        if (sq * sq == sum) {
            for (auto n : nums)
                cout << n << ' ';
            cout << sq << '\n';
            return 0;
        }
    }

    return 0;
}
