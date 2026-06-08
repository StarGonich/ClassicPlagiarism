#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <iomanip>
#include <cmath>

using namespace std;
long long calculate_window_time(long long N_start, long long N_end, const vector<pair<long long, long long>>& ads) {
    long long total_time = 0;
    for (const auto& ad : ads) {
        long long overlap_start = max(N_start, ad.first);
        long long overlap_end = min(N_end, ad.second);
        if (overlap_start < overlap_end) {
            total_time += (overlap_end - overlap_start);
        }
    }
    return total_time;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    long long T;
    if (!(cin >> T)) return 0;

    vector<pair<long long, long long>> ads(N);
    for (int i = 0; i < N; ++i) {
        cin >> ads[i].first >> ads[i].second;
    }

    int left = 0;
    long long current_window_ad_time = 0;
    long long earliest_N = -1;
    bool violation_found = false;

    vector<long long> critical_Ns;
    for (const auto& ad : ads) {
        critical_Ns.push_back(ad.first);
        critical_Ns.push_back(ad.second - 3600);
    }
    sort(critical_Ns.begin(), critical_Ns.end());
    critical_Ns.erase(unique(critical_Ns.begin(), critical_Ns.end()), critical_Ns.end());


    for (long long N_val : critical_Ns) {
        if (N_val < 0) continue;
        long long window_end = N_val + 3600;
        long long current_sum = 0;
        for (int j = 0; j < N; ++j) {
             if (ads[j].first >= window_end) break;
             if (ads[j].second <= N_val) continue;

             long long overlap_start = max(N_val, ads[j].first);
             long long overlap_end = min(window_end, ads[j].second);
             
             if (overlap_start < overlap_end) {
                 current_sum += (overlap_end - overlap_start);
             }
        }
        
        if (current_sum > T) {
            cout << N_val << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
