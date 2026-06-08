#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int check_advertising(int N, int T, vector<pair<int, int>>& intervals) {
    vector<long long> ads(3600, 0);

    for (const auto& interval : intervals) {
        int start = interval.first % 3600;
        int end = interval.second % 3600;

        if (start < end) {
            for (int i = start; i < end; i++) {
                ads[i]++;
            }
        } else {
            for (int i = start; i < 3600; i++) {
                ads[i]++;
            }
            for (int i = 0; i < end; i++) {
                ads[i]++;
            }
        }
    }

    for (int i = 0; i < 3600; ++i) {
        long long total_ads = 0;
        for (int j = 0; j < 3600; ++j) {
            total_ads += ads[(i + j) % 3600];
        }
        if (total_ads > T) {
            return i;
        }
    }

    return -1;
}

int main() {
    int N, T;
    cin >> N >> T;
    vector<pair<int, int>> intervals(N);
    for (int i = 0; i < N; ++i) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    cout << check_advertising(N, T, intervals) << endl;
    return 0;
}
