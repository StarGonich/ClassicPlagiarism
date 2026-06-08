#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, T;
    cin >> N >> T;
    vector<pair<long long, long long>> intervals(N);
    long long max_time = 0;

    for (int i = 0; i < N; ++i) {
        cin >> intervals[i].first >> intervals[i].second;
        max_time = max(max_time, intervals[i].second);
    }

    vector<long long> ad_time(max_time + 1, 0);

    for (const auto& interval : intervals) {
        ad_time[interval.first]++;
        ad_time[interval.second]--;
    }

    for (int i = 1; i <= max_time; ++i) {
        ad_time[i] += ad_time[i - 1];
    }

    for (long long start = 0; start <= max_time - 3600; ++start) {
        long long total_ads = 0;
        for (long long j = start; j < start + 3600; ++j) {
            total_ads += ad_time[j];
        }
        if (total_ads > T) {
            cout << start << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
