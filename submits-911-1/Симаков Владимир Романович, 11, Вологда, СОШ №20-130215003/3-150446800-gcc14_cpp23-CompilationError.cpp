#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
struct Interval {
    long long start;
    long long end;
};

bool compareIntervals(const Interval& a, const Interval& b) {
    return a.start < b.start;
}
vector<Interval> mergeIntervals(vector<Interval>& intervals) {
    if (intervals.empty()) return {};
    sort(intervals.begin(), intervals.end(), compareIntervals);

    vector<Interval> merged;
    merged.push_back(intervals[0]);

    for (size_t i = 1; i < intervals.size(); ++i) {
        if (intervals[i].start < merged.back().end) {
            if (intervals[i].end > merged.back().end) {
                merged.back().end = intervals[i].end;
            }
        } else {
            merged.push_back(intervals[i]);
        }
    }
    return merged;
}

long long checkWindow(long long N, long long T, vector<Interval>& ads) {
    vector<Interval> merged_ads = mergeIntervals(ads);
    int M = merged_ads.size();
    if (M == 0) return -1;
    int right = 0;
    long long current_ad_time = 0;
    for (int left = 0; left < M; ++left) {
        long long window_start = merged_ads[left].start;
        long long window_end = window_start + 3600;
        current_ad_time = 0;
        while (right < M && merged_ads[right].start < window_end) {
            long long overlap_start = max(window_start, merged_ads[right].start);
            long long overlap_end = min(window_end, merged_ads[right].end);
            
            if (overlap_start < overlap_end) {
                current_ad_time += (overlap_end - overlap_start);
            }

            right++;
        }
    }
    auto calculateTimeInWindow = [&](long long start, long long end) -> long long {
        long long total_ad = 0;
        for(const auto& ad : merged_ads) {
            long long overlap_start = max(start, ad.start);
            long long overlap_end = min(end, ad.end);
            if (overlap_start < overlap_end) {
                total_ad += (overlap_end - overlap_start);
            }
        }
        return total_ad;
    };
    for (const auto& ad : merged_ads) {
        long long window_start = ad.start;
        if (calculateTimeInWindow(window_start, window_start + 3600) > T) {
            return window_start;
        }
    }
    map<long long, int> events;
    for(const auto& ad : ads) {
        events[ad.start]++;
        events[ad.end]--;
    }

    vector<pair<long long, int>> sorted_events(events.begin(), events.end());
    vector<long long> time_points;
    vector<long long> prefix_sum_ad_time;

    long long current_count = 0;
    long long last_time = sorted_events[0].first;
    long long cumulative_time = 0;

    for(const auto& event : sorted_events) {
        long long current_time = event.first;
        if (current_count > 0) {
            cumulative_time += (current_time - last_time);
        }
        current_count += event.second;
        last_time = current_time;
        time_points.push_back(current_time);
        prefix_sum_ad_time.push_back(cumulative_time);
    }
    for(size_t i = 0; i < time_points.size(); ++i) {
        long long window_start = time_points[i];
        long long window_end = window_start + 3600;
        auto it = upper_bound(time_points.begin(), time_points.end(), window_end);
        int j = static_cast<int>(it - time_points.begin()) - 1;
        long long total_ad_in_window = prefix_sum_ad_time[j] - prefix_sum_ad_time[i];
    }

    vector<long long> potential_starts;
    for(const auto& ad : ads) {
        potential_starts.push_back(ad.start);
        potential_starts.push_back(ad.end - 3600);
    }
    sort(potential_starts.begin(), potential_starts.end());

    auto getCoveredTime = [&](long long start, long long end) -> long long {
        auto it_start = upper_bound(time_points.begin(), time_points.end(), start);
        int idx_start = static_cast<int>(it_start - time_points.begin()) - 1;

        auto it_end = upper_bound(time_points.begin(), time_points.end(), end);
        int idx_end = static_cast<int>(it_end - time_points.begin()) - 1;

        long long total = prefix_sum_ad_time[idx_end] - prefix_sum_ad_time[idx_start];
    vector<Interval> merged = mergeIntervals(ads);
    int M = merged.size();
    int right_ptr = 0;
    long long total_ad_time = 0;
    vector<long long> candidate_starts;
    for(const auto& ad : ads) {
        candidate_starts.push_back(ad.start);
        candidate_starts.push_back(ad.end - 3600);
    }
    sort(candidate_starts.begin(), candidate_starts.end());
    for (long long N_start : candidate_starts) {
        if (N_start < 0) continue;

    }

    auto calculateOverlapFast = [&](long long start, long long end) -> long long {
        auto it = lower_bound(merged.begin(), merged.end(), start, [](const Interval& a, long long val){
            return a.end < val;
        });

    };

    vector<long long> cumulative_lengths;
    long long current_length = 0;
    for(const auto& ad : merged_ads) {
        current_length += (ad.end - ad.start);
        cumulative_lengths.push_back(current_length);
    }

    auto getCoveredTimeInRange = [&](long long start, long long end) -> long long {
        auto it_start = lower_bound(merged_ads.begin(), merged_ads.end(), start, [](const Interval& a, long long val){
            return a.end <= val;
        });
        int idx_s = static_cast<int>(it_start - merged_ads.begin());
        auto it_end = lower_bound(merged_ads.begin() + idx_s, merged_ads.end(), end, [](const Interval& a, long long val){
            return a.start < val;
        });
        int idx_e = static_cast<int>(it_end - merged_ads.begin()) - 1;

        if (idx_s > idx_e) return 0;

        long long total = cumulative_lengths[idx_e];
        if (idx_s > 0) total -= cumulative_lengths[idx_s - 1];
        long long partial_start = max(start, merged_ads[idx_s].start);
        long long partial_end = min(end, merged_ads[idx_e].end);

        total -= (partial_start - merged_ads[idx_s].start);
        total -= (merged_ads[idx_e].end - partial_end);
    int right_ptr = 0;
    long long current_ad_time = 0;
}
