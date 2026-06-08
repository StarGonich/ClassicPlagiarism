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
    long long total_time = 0;
    long long last_time = 0;

    for (const auto& event : events) {
        long long current_time = event.first;

        if (current_time - last_time >= 3600) {
            if (current_ads > T) {
                cout << last_time << endl;
                return 0;
            }
            total_time += current_time - last_time;
        }

        current_ads += event.second;
        last_time = current_time;
    }

    for (long long i = last_time; i < last_time + 3600; ++i) {
        if (current_ads > T) {
            cout << last_time << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
