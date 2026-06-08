#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int check_advertising(int N, int T, vector<pair<int, int>>& intervals) {
    vector<pair<long long, int>> events;

    for (const auto& interval : intervals) {
        events.emplace_back(interval.first, 1);
        events.emplace_back(interval.second, -1);
    }

    sort(events.begin(), events.end());
    
    long long current_ads = 0;
    long long current_time = 0;
    int left = 0;

    for (size_t right = 0; right < events.size(); ++right) {
        long long time_diff = events[right].first - current_time;
        current_ads += time_diff >= 3600 ? 0 : (time_diff * (left > right ? 1 : current_ads));

        while (left < right && events[right].first - events[left].first >= 3600) {
            current_ads -= (events[left + 1].first - events[left].first);
            left++;
        }

        current_time = events[right].first;
        current_ads += events[right].second;

        if (events[right].first >= 3600 && current_ads > T) {
            return current_time - 3600;
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
