#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long T;
    cin >> N >> T;
    
    vector<pair<long long, int>> events;
    for (int i = 0; i < N; ++i) {
        long long start, end;
        cin >> start >> end;
        events.push_back({start, 1});
        events.push_back({end, -1});
    }
    sort(events.begin(), events.end());

    long long window_size = 3600;
    long long current_ads = 0;
    long long right = 0;
    long long last_ad_end = 0;
    if (!events.empty()) {
        last_ad_end = events.back().first;
    }

    for (long long left = 0; left < events.size(); ++left) {
        long long current_time = events[left].first;
        while (right < events.size() && events[right].first < current_time + window_size) {
            current_ads += events[right].second;
            right++;
        }
        if (current_ads > T) {
            cout << current_time << endl;
            return 0;
        }
        long long next_event_time = (left + 1 < events.size()) ? events[left + 1].first : last_ad_end + window_size;
        long long time_to_slide = next_event_time - current_time;

        if (current_ads > T) {
            cout << current_time << endl;
            return 0;
        }
        long long temp_ads_to_subtract = 0;
        while (left < events.size() && events[left].first == current_time) {
            temp_ads_to_subtract += events[left].second;
            left++;
        }
        current_ads -= temp_ads_to_subtract;
        left--;
    }

    cout << -1 << endl;
    return 0;
}
