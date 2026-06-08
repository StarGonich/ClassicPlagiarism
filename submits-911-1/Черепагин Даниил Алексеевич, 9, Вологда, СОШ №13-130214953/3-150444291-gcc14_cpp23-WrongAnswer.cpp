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
    
    // Перебираем все возможные начала часовых интервалов
    for (int left = 0; left < N; left++) {
        long long window_start = ads[left].first;
        long long window_end = window_start + 3600;
        
        // Сдвигаем правый указатель, пока реклама попадает в окно
        while (right < N && ads[right].first < window_end) {
            current_sum += min(ads[right].second, window_end) - ads[right].first;
            right++;
        }
        
        // Проверяем условие
        if (current_sum > T) {
            result = window_start;
            break;
        }
        
        // Убираем левую рекламу из суммы
        current_sum -= min(ads[left].second, window_end) - ads[left].first;
        
        // Если правый указатель ушел за левый, сдвигаем его обратно
        if (right <= left + 1) {
            right = left + 1;
            current_sum = 0;
        }
    }
    
    cout << result << endl;
    
    return 0;
}