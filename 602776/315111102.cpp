#include <iostream>
#include <vector>
#include <cassert>
#include <cstdint>

using namespace std;

const int N = 1000 + 1;

vector<int> ans[N];

int main() {
    ans[1] = {1};
    ans[2] = {3, 4};
    ans[3] = {1, 2, 2};

    for (int i = 0; i < N; i++) {
        if (ans[i].size()) {
            for (int k = 2; k * k < N; k++) {
                for (int t = 1; t <= k * k && t * i + k * k - t < N; t++) {
                    int ind = t * i + k * k - t;
                    if (ans[ind].size()) continue;
                    int64_t sum = 0;
                    for (int kek : ans[i]) {
                        sum += 1LL * kek * kek;
                    }
                    sum = sqrt(sum);
                    for (int j = 0; j < t; j++) {
                        for (int kek : ans[i]) {
                            ans[ind].push_back(kek);
                        }
                    }
                    for (int j = 0; j < k * k - t; j++) {
                        ans[ind].push_back(sum);
                    }
                }
            }
        }
    }

    /*
    for (int i = 0; i < N; i++) {
        cout << i << ":\t" << ans[i].size() << endl;
        int64_t sum = 0;
        for (int j : ans[i]) {
            assert(1 <= j && j <= (int)1e9);
            sum += 1LL * j * j;
        }
        int64_t root = sqrt(sum);
        assert(sum == root * root);
    }
    */

    int n;
    cin >> n;
    int64_t sum = 0;
    for (int i : ans[n]) {
        cout << i << " ";
        sum += 1LL * i * i; 
    }
    int64_t root = sqrt(sum);
    cout << root << "\n";
}