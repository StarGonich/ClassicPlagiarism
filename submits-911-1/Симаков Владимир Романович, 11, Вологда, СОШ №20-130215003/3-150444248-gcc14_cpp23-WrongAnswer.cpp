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
    
    if (ad_changes.empty()) {
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
    
    long long current_time = 0;
    long long window_start_time = 0;
    
    int left_ptr = 0;
    int right_ptr = 0;

    while (right_ptr < events.size()) {
        long long next_event_time = events[right_ptr].first;
        long long segment_end = min(next_event_time, window_start_time + window_size);
        current_total_ads += current_ads * (segment_end - current_time);
        while (window_start_time + window_size < next_event_time) {
            if (current_total_ads > T) {
                cout << window_start_time << endl;
                return 0;
            }
            long long slide_amount = events[left_ptr].first - window_start_time;
            current_total_ads -= current_ads * slide_amount;
            current_ads -= events[left_ptr].second;
            window_start_time = events[left_ptr].first;
            left_ptr++;
        }
        current_ads += events[right_ptr].second;
        current_time = next_event_time;
        right_ptr++;
    }
    while (window_start_time + window_size <= current_time) {
        if (current_total_ads > T) {
            cout << window_start_time << endl;
            return 0;
        }
        long long slide_amount = events[left_ptr].first - window_start_time;
        current_total_ads -= current_ads * slide_amount;
        current_ads -= events[left_ptr].second;
        window_start_time = events[left_ptr].first;
        left_ptr++;
    }

    cout << -1 << endl;
    return 0;
}
