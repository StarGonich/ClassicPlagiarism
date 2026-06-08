#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <iomanip>

using namespace std;
struct Event {
    long long time;
    int type;
    bool operator<(const Event& other) const {
        if (time != other.time) {
            return time < other.time;
        }
        return type > other.type;
    }
};

long long solve_ad_law(int N, long long T, const vector<pair<long long, long long>>& ads) {
    vector<Event> events;
    for (const auto& ad : ads) {
        events.push_back({ad.first, 1});
        events.push_back({ad.second, -1});
    }
    sort(events.begin(), events.end());
    long long max_overlap = 0;
    long long current_overlap = 0;
    int left_event_idx = 0;
    long long best_N = -1;
    bool found = false;
    for (int right_event_idx = 0; right_event_idx < events.size(); ++right_event_idx) {
        current_overlap += (long long)events[right_event_idx].type;
        while (events[left_event_idx].time < events[right_event_idx].time - 3600) {
            current_overlap -= (long long)events[left_event_idx].type;
            left_event_idx++;
        }
        
        if (current_overlap > T) {
            long long potential_N = events[right_event_idx].time - 3600;

            if (!found) {
                best_N = potential_N;
                found = true;
            } else {
                return potential_N;
            }
        }
    }

    if (found) return best_N;
    return -1;
}
long long find_earliest_N(int N, long long T, const vector<pair<long long, long long>>& ads) {
    
    int left = 0;
    for (int right = 0; right < N; ++right) {
        long long start_time = ads[right].first;
        long long end_time = ads[right].second;
    }

    int left_ad = 0;
    for (int right_ad = 0; right_ad < N; ++right_ad) {
    }
    return -1;
}
long long find_earliest_N_sweep(int N, long long T, const vector<pair<long long, long long>>& ads) {
    vector<pair<long long, int>> events;
    for(const auto& ad : ads) {
        events.push_back({ad.first, 1});
        events.push_back({ad.second, -1});
    }
    sort(events.begin(), events.end());

    int left = 0;
    long long current_total_time = 0;

    for (int right = 0; right < N; ++right) {
    }
    return -1;
}
long long get_earliest_N(int N, long long T, const vector<pair<long long, long long>>& ads) {
    int left = 0;
    long long current_total_overlap_length = 0;
    
    vector<pair<long long, long long>> events;
    for(const auto& ad : ads) {
        events.push_back({ad.first, ad.second - ad.first});
    }
    
    long long earliest_N = -1;
    bool found = false;
    int left_ad_idx = 0;

    for (int right_ad_idx = 0; right_ad_idx < N; ++right_ad_idx) {
        long long window_end_time = ads[right_ad_idx].first + 3600;
    }
    return -1;
}
long long final_solution(int N, long long T, const vector<pair<long long, long long>>& ads) {
    
    int left = 0;
    
    for (int i = 0; i < N; ++i) {
        long long potential_N = ads[i].first;
        long long window_end = potential_N + 3600;
        long long total_ad_time_in_window = 0;

        int j = i;
        long long current_sum = 0;

        while (j < N && ads[j].first < window_end) {
            long long overlap_start = max(potential_N, ads[j].first);
            long long overlap_end = min(window_end, ads[j].second);
            
            if (overlap_start < overlap_end) {
                current_sum += (overlap_end - overlap_start);
            }
            j++;
        }

        if (current_sum > T) {
            return potential_N;
        }
    }
    
    for (int i = 0; i < N; ++i) {
        long long potential_N = ads[i].second - 3600;
    }
    return -1;
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

    for (int i = 0; i < N; ++i) {
        long long potential_N = ads[i].first;
        long long window_end = potential_N + 3600;
        long long current_sum = 0;
        
        for (int j = i; j < N; ++j) {
            if (ads[j].first >= window_end) break;
            
            long long overlap_start = max(potential_N, ads[j].first);
            long long overlap_end = min(window_end, ads[j].second);
            
            if (overlap_start < overlap_end) {
                current_sum += (overlap_end - overlap_start);
            }
        }
        
        if (current_sum > T) {
            cout << potential_N << endl;
            return 0;
        }
    }

    for (int i = 0; i < N; ++i) {
        long long potential_N = ads[i].second - 3600;
        if (potential_N < 0) continue;

        long long window_end = potential_N + 3600;
        long long current_sum = 0;
        
        for (int j = 0; j < N; ++j) {
             if (ads[j].first >= window_end) break;
             if (ads[j].second <= potential_N) continue;

             long long overlap_start = max(potential_N, ads[j].first);
             long long overlap_end = min(window_end, ads[j].second);
             
             if (overlap_start < overlap_end) {
                 current_sum += (overlap_end - overlap_start);
             }
        }

        if (current_sum > T) {
        }
    }
    
    vector<pair<long long, int>> events;
    for(const auto& ad : ads) {
        events.push_back({ad.first, 1});
        events.push_back({ad.second, -1});
    }
    sort(events.begin(), events.end());
    
    long long currentTime = 0;
    long long overlapCount = 0;
    long long totalTimeInWindow = 0;
    
    int left_ad_ptr = 0;
    long long current_window_time = 0;
    long long earliest_valid_N = -1;
    bool found_violation = false;

    vector<long long> potential_Ns;
    for (const auto& ad : ads) {
        potential_Ns.push_back(ad.first);
        potential_Ns.push_back(ad.second - 3600);
    }
    sort(potential_Ns.begin(), potential_Ns.end());
    
    for (long long N_val : potential_Ns) {
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

