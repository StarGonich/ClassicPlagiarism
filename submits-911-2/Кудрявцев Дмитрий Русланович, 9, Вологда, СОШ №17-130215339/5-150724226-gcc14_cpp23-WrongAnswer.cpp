#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cmath>

using namespace std;

// Функция для вычисления F1-метрики
double computeF1(int TP, int FP, int FN) {
    if (TP == 0 && FP == 0 && FN == 0) return 0.0;
    double precision = (TP + FP == 0) ? 0.0 : static_cast<double>(TP) / (TP + FP);
    double recall = (TP + FN == 0) ? 0.0 : static_cast<double>(TP) / (TP + FN);
    
    if (precision == 0.0 && recall == 0.0) return 0.0;
    return 2.0 * precision * recall / (precision + recall);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    int K;
    cin >> K;

    vector<bool> is_fraud(N, false);
    for (int i = 0; i < K; ++i) {
        int idx;
        cin >> idx;
        is_fraud[idx - 1] = true;  // переводим в 0-индексацию
    }

    // Создаём вектор пар (оценка P, является ли фродом)
    vector<pair<int, bool>> points;
    for (int i = 0; i < N; ++i) {
        points.push_back({P[i], is_fraud[i]});
    }

    // Сортируем по возрастанию P
    sort(points.begin(), points.end());

    // Общее количество фрод-сообщений
    int total_fraud = K;

    // Счётчики: начинаем с порога T > max(P) → никто не фрод
    int TP = 0;  // истинно фрод (фрод и классифицирован как фрод)
    int FP = 0;  // ложно фрод (не фрод, но классифицирован как фрод)
    // FN = total_fraud - TP (все фрод-сообщения, которые не попали)
    // TN не нужен для F1

    double best_F1 = -1;
    int best_T = -1;

    // Перебираем возможные пороги T: для каждого уникального значения P
    // Порог T = points[i].first означает: классифицируем как фрод, если P >= T
    // Мы будем обновлять счётчики *после* расчёта F1 для текущего T
    for (int i = 0; i < N; ++i) {
        // Если текущее значение P отличается от предыдущего, проверяем порог T = P[i]
        if (i == 0 || points[i].first != points[i-1].first) {
            // Рассчитываем F1 для порога T = points[i].first
            int FN = total_fraud - TP;
            double F1 = computeF1(TP, FP, FN);

            // Обновляем лучший результат
            if (F1 > best_F1 || (F1 == best_F1 && (best_T == -1 || points[i].first < best_T))) {
                best_F1 = F1;
                best_T = points[i].first;
            }
        }

        // Теперь добавляем текущую точку в счётчики (так как при T <= points[i].first она будет считаться фродом)
        if (points[i].second) {
            TP++;
        } else {
            FP++;
        }
    }

    // Проверим крайний случай: T = min(P) уже учтён, но на всякий случай — если не было обновления
    // На самом деле, T = min(P) обрабатывается при i=0
    // Дополнительно: проверим случай T = max(P)+1 (никто не фрод) — он уже учтён перед циклом (TP=0, FP=0)

    // Выводим оптимальный порог T
    cout << best_T << endl;

    return 0;
}
