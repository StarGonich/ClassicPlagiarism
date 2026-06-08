#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, T;
    cin >> N >> T;
    
    long long max_time = 0;
    vector<pair<long long, long long>> intervals(N);
    for (int i = 0; i < N; ++i) {
        cin >> intervals[i].first >> intervals[i].second;
        max_time = max(max_time, intervals[i].second);
    }

    vector<long long> ad_time(max_time + 2, 0);

    for (const auto& interval : intervals) {
        ad_time[interval.first]++;
        if (interval.second + 1 <= max_time + 1) {
            ad_time[interval.second]--;
        }
    }

    for (int i = 1; i <= max_time; ++i) {
        ad_time[i] += ad_time[i - 1];
    }

    // Use a sliding window approach for the final loop
    long long window_size = 3600;
    if (window_size > max_time) {
        long long total_ads = 0;
        for (long long j = 0; j < max_time; ++j) {
            total_ads += ad_time[j];
        }
        if (total_ads > T) {
            cout << 0 << endl;
            return 0;
        }
        cout << -1 << endl;
        return 0;
    }

    long long current_total_ads = 0;
    for (long long i = 0; i < window_size; ++i) {
        current_total_ads += ad_time[i];
    }

    if (current_total_ads > T) {
        cout << 0 << endl;
        return 0;
    }

    for (long long start = 1; start <= max_time - window_size; ++start) {
        current_total_ads += ad_time[start + window_size - 1] - ad_time[start - 1];
        if (current_total_ads > T) {
            cout << start << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
