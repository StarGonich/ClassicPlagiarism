#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cmath>

using namespace std;

// Функция для вычисления F1-метрики
double computeF1(int TP, int FP, int FN) {
    double precision = (TP + FP == 0) ? 0.0 : (double)TP / (TP + FP);
    double recall = (TP + FN == 0) ? 0.0 : (double)TP / (TP + FN);

    if (precision == 0.0 && recall == 0.0) {
        return 0.0;
    }

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

    unordered_set<int> fraudSet;
    for (int i = 0; i < K; ++i) {
        int idx;
        cin >> idx;
        fraudSet.insert(idx - 1); // переводим в 0-индексацию
    }

    // Создаём вектор пар (оценка, индекс), чтобы отсортировать по P, сохраняя индексы
    vector<pair<int, int>> scoredPoints;
    for (int i = 0; i < N; ++i) {
        scoredPoints.push_back({P[i], i});
    }

    // Сортируем по оценке P
    sort(scoredPoints.begin(), scoredPoints.end());

    // Получаем уникальные значения P (кандидаты для T), но проще перебирать по отсортированному массиву
    double best_F1 = -1;
    int best_T = -1;

    // Общее количество фрод-сообщений
    int total_fraud = K;
    int total_non_fraud = N - K;

    // Перебираем все возможные пороги T — уникальные значения из P
    // Но можно пройти по отсортированному scoredPoints и проверять каждый уникальный score как T
    for (int i = 0; i < N; ++i) {
        // Пропускаем дубли: обрабатываем только первое вхождение каждого значения P
        if (i > 0 && scoredPoints[i].first == scoredPoints[i-1].first) {
            continue;
        }

        int T = scoredPoints[i].first;

        // Классифицируем: сообщения с P[j] >= T — фрод
        int TP = 0; // правильно распознанные фрод-сообщения
        int FP = 0; // ошибочно распознанные как фрод (на самом деле не фрод)

        for (int j = 0; j < N; ++j) {
            if (P[j] >= T) {
                if (fraudSet.count(j)) {
                    TP++;
                } else {
                    FP++;
                }
            }
        }

        int FN = total_fraud - TP; // пропущенные фрод-сообщения

        double F1 = computeF1(TP, FP, FN);

        // Обновляем лучший результат
        if (F1 > best_F1 || (F1 == best_F1 && (best_T == -1 || T < best_T))) {
            best_F1 = F1;
            best_T = T;
        }
    }

    // Выводим оптимальный порог T
    cout << best_T << endl;

    return 0;
}
