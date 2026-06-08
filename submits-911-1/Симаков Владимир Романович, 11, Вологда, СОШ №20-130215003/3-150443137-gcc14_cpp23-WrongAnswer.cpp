#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, T;
    cin >> N >> T;
    vector<pair<long long, int>> events;

    for (int i = 0; i < N; ++i) {
        long long start, end;
        cin >> start >> end;
        events.emplace_back(start, 1);
        events.emplace_back(end, -1);
    }

    sort(events.begin(), events.end());

    long long current_ads = 0;
    long long last_time = 0;
    long long violating_time = -1;

    for (const auto& event : events) {
        long long current_time = event.first;

        if (current_ads > T) {
            violating_time = last_time;
        }

        long long duration = current_time - last_time;
        if (current_ads > 0) {
            current_ads += (duration >= 3600) ? (duration - 3600) : duration; 
        }

        last_time = current_time;
        current_ads += event.second;
    }

    if (violating_time != -1) {
        cout << violating_time << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
