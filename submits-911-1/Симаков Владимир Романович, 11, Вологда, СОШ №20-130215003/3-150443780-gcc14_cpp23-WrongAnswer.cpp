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

    map<long long, long long> ad_events;
    for (int i = 0; i < N; ++i) {
        long long start, end;
        cin >> start >> end;
        ad_events[start]++;
        ad_events[end]--;
    }

    long long window_size = 3600;
    long long current_time = 0;
    long long current_ads = 0;
    long long current_total_ads = 0;
    auto it = ad_events.begin();
    long long window_end_time = window_size;
    while (it != ad_events.end() && it->first <= window_end_time) {
        long long next_time = it->first;
        current_total_ads += current_ads * (next_time - current_time);
        current_time = next_time;
        current_ads += it->second;
        ++it;
    }
    current_total_ads += current_ads * (window_end_time - current_time);
    if (current_total_ads > T) {
        cout << 0 << endl;
        return 0;
    }
    auto left_it = ad_events.begin();

    while (it != ad_events.end()) {
        long long prev_window_start = (left_it == ad_events.end()) ? 0 : left_it->first;
        long long prev_ads = (left_it == ad_events.end()) ? 0 : left_it->second;

        long long next_window_end_time = it->first;
        long long next_ads_change = it->second;
        long long slide_amount = next_window_end_time - (prev_window_start + window_size);
        if (slide_amount > 0) {
            long long prev_window_total_ads = current_total_ads;
            current_total_ads -= (current_ads - prev_ads) * slide_amount;
            
            if (current_total_ads > T) {
                cout << prev_window_start + 1 << endl;
                return 0;
            }
        }
        
        current_total_ads -= (current_ads - prev_ads) * (left_it->first - prev_window_start);
        current_total_ads += current_ads * (next_window_end_time - current_time);
        
        current_ads -= prev_ads;
        current_ads += next_ads_change;
        
        current_time = next_window_end_time;
        
        ++left_it;
        ++it;

        if (current_total_ads > T) {
            cout << current_time - window_size << endl;
            return 0;
        }
    }
    if (!ad_events.empty()) {
        long long last_event_time = ad_events.rbegin()->first;
        long long last_window_start = max(0LL, last_event_time - window_size);
        long long total_ads_at_last_event = 0;
        for (auto const& [time, change] : ad_events) {
            if (time < last_window_start) {
                total_ads_at_last_event += change;
            }
        }
        long long last_total_ads = total_ads_at_last_event * (last_event_time - last_window_start);
        for (long long t = last_event_time - window_size; t < last_event_time; ++t) {
            if (last_total_ads > T) {
                cout << t << endl;
                return 0;
            }
        }
    }


    cout << -1 << endl;
    return 0;
}
