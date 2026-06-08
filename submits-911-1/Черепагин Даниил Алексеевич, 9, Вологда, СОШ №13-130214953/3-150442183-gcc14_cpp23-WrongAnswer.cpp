#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, T;
    cin >> N >> T;
    
    vector<pair<long long, long long>> ads(N);
    for (int i = 0; i < N; i++) {
        cin >> ads[i].first >> ads[i].second;
    }
    
    long long result = -1;
    int right = 0;
    long long current_sum = 0;
    
    for (int left = 0; left < N; left++) {
        long long window_start = ads[left].first;
        long long window_end = window_start + 3600;
        
        // Добавляем новые рекламы, которые попадают в окно
        while (right < N && ads[right].first < window_end) {
            long long ad_start = ads[right].first;
            long long ad_end = ads[right].second;
            long long overlap = min(ad_end, window_end) - max(ad_start, window_start);
            current_sum += max(0LL, overlap);
            right++;
        }
        
        if (current_sum > T) {
            result = window_start;
            break;
        }
        
        // Убираем левую рекламу
        long long left_ad_start = ads[left].first;
        long long left_ad_end = ads[left].second;
        long long left_overlap = min(left_ad_end, window_end) - max(left_ad_start, window_start);
        current_sum -= max(0LL, left_overlap);
    }
    
    cout << result << endl;
    
    return 0;
}