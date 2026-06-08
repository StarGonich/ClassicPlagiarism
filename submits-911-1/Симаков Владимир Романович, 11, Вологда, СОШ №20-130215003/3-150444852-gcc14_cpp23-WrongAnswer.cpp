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
    long long current_time = 0;
    int events_count = events.size();
    int right = 0;
    for (int left = 0; left < events_count; ++left) {
        current_time = events[left].first;
        while (right < events_count && events[right].first < current_time + window_size) {
            current_ads += events[right].second;
            right++;
        }
        if (current_ads > T) {
            cout << current_time << endl;
            return 0;
        }
        current_ads -= events[left].second;
    }
    if (current_ads <= T) {
         cout << -1 << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
