#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iomanip>  // для работы с точностью вывода

using namespace std;

struct Message {
    int score;
    bool is_fraud;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> scores(n);
    for(int i = 0; i < n; ++i) {
        cin >> scores[i];
    }
    
    int k;
    cin >> k;
    
    set<int> fraud_indices;
    for(int i = 0; i < k; ++i) {
        int idx;
        cin >> idx;
        fraud_indices.insert(idx - 1);  // Переводим в 0-based индексацию
    }
    
    // Создаем вектор сообщений
    vector<Message> messages;
    for(int i = 0; i < n; ++i) {
        messages.push_back({scores[i], fraud_indices.count(i) > 0});
    }
    
    // Сортируем сообщения по убыванию оценки
    sort(messages.begin(), messages.end(), [](const Message& a, const Message& b) {
        return a.score > b.score;
    });
    
    double max_f1 = 0.0;
    int best_threshold = 1e9;
    int tp = 0, fp = 0, fn = k;
    
    // Добавляем дополнительную проверку для всех возможных порогов
    for(int i = 0; i <= n; ++i) {  // проверяем также случай, когда все сообщения не фрод
        double current_threshold;
        if (i < n) {
            current_threshold = messages[i].score;
        } else {
            current_threshold = 0;  // случай, когда все сообщения не фрод
        }
        
        // Обновляем счетчики
        if (i > 0) {
            if (messages[i-1].is_fraud) {
                tp--;
                fn++;
            } else {
                fp--;
            }
        }
        
        double precision = (tp == 0) ? 0.0 : static_cast<double>(tp) / (tp + fp);
        double recall = (tp == 0) ? 0.0 : static_cast<double>(tp) / k;
        
        double f1 = 0.0;
        if (precision + recall > 0) {
            f1 = 2 * precision * recall / (precision + recall);
        }
        
        // Обновляем лучший порог
        if (f1 > max_f1 || (f1 == max_f1 && current_threshold < best_threshold)) {
            max_f1 = f1;
            best_threshold = current_threshold;
        }
    }
    
    cout << best_threshold << endl;
    
    return 0;
}
