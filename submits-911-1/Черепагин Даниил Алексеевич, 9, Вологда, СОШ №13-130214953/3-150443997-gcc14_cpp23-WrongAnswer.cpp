#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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
    
    // Рассматриваем только интересные моменты времени: начала и концы рекламы
    vector<long long> events;
    for (int i = 0; i < N; i++) {
        events.push_back(ads[i].first);
        events.push_back(ads[i].second);
        // Также добавляем время за 3600 секунд до конца рекламы
        if (ads[i].second >= 3600) {
            events.push_back(ads[i].second - 3600);
        }
    }
    
    // Сортируем и удаляем дубликаты
    sort(events.begin(), events.end());
    events.erase(unique(events.begin(), events.end()), events.end());
    
    // Для каждого кандидата проверяем часовое окно
    for (long long start : events) {
        if (start < 0) continue;
        
        long long end = start + 3600;
        long long total_ad_time = 0;
        
        // Находим все рекламы, пересекающиеся с окном [start, end]
        for (int i = 0; i < N; i++) {
            if (ads[i].second <= start) continue; // реклама закончилась до начала окна
            if (ads[i].first >= end) break; // реклама началась после конца окна
            
            // Вычисляем длительность пересечения
            long long overlap_start = max(ads[i].first, start);
            long long overlap_end = min(ads[i].second, end);
            total_ad_time += overlap_end - overlap_start;
            
            if (total_ad_time > T) {
                if (result == -1 || start < result) {
                    result = start;
                }
                break;
            }
        }
        
        if (result != -1 && result == start) {
            break;
        }
    }
    
    cout << result << endl;
    
    return 0;
}