#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int check_advertising(int N, int T, vector<pair<int, int>>& intervals) {
    vector<pair<int, int>> events;

    for (auto& interval : intervals) {
        events.push_back({interval.first, 1});
        events.push_back({interval.second, -1});
    }

    sort(events.begin(), events.end());

    vector<long long> ad_time_count(1000001, 0);
    int current_ads = 0;
    int last_time = 0;

    for (auto& event : events) {
        if (current_ads > 0) {
            ad_time_count[last_time] += event.first - last_time;
        }
        current_ads += event.second;
        last_time = event.first;
    }

    for (int start = 0; start <= 1000000 - 3600; ++start) {
        long long total_ads = 0;
        for (int j = start; j < start + 3600; ++j) {
            total_ads += ad_time_count[j];
        }
        if (total_ads > T) {
            return start;
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
