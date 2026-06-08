#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, T;
    cin >> N >> T;

    map<long long, long long> ad_changes;
    for (int i = 0; i < N; ++i) {
        long long start, end;
        cin >> start >> end;
        ad_changes[start]++;
        ad_changes[end]--;
    }
    if (ad_changes.empty() && T >= 0) {
        cout << -1 << endl;
        return 0;
    }

    vector<pair<long long, long long>> events;
    for (auto const& [time, change] : ad_changes) {
        events.push_back({time, change});
    }

    long long window_size = 3600;
    long long current_ads = 0;
    long long current_total_ads = 0;
    long long window_start_time = 0;
    int left_ptr = 0;
    int right_ptr = 0;
    long long current_time = 0;
    while (right_ptr < events.size() || current_ads > 0) {
        long long next_event_time = (right_ptr < events.size()) ? events[right_ptr].first : window_start_time + window_size + 1;
        long long next_window_start_check = max(current_time, window_start_time);
        long long segment_end = min(next_event_time, window_start_time + window_size);
        if (segment_end > next_window_start_check) {
            current_total_ads += current_ads * (segment_end - next_window_start_check);
        }
        while (window_start_time + window_size < next_event_time) {
            if (current_total_ads > T) {
                cout << window_start_time << endl;
                return 0;
            }
            long long slide_by = min(window_size, next_event_time - (window_start_time + window_size));
            if (current_ads == 0) {
                slide_by = max(1LL, next_event_time - (window_start_time + window_size));
            }

            window_start_time += slide_by;
            current_total_ads = current_total_ads - (current_ads * slide_by);
            if (current_total_ads > T) {
                 cout << window_start_time << endl;
                return 0;
            }
        }
        current_time = next_event_time;
        if (right_ptr < events.size()) {
            current_ads += events[right_ptr].second;
            right_ptr++;
        }
    }
    if (current_total_ads > T) {
        cout << window_start_time << endl;
        return 0;
    }

    cout << -1 << endl;
    return 0;
}
