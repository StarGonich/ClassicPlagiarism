#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

// Структура для хранения точки
struct Point {
    int x, y, c;
    Point(int x = 0, int y = 0, int c = 0) : x(x), y(y), c(c) {}
};

// Функция для вычисления квадрата евклидова расстояния между двумя точками
long long distSq(const Point& a, const Point& b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    return dx * dx + dy * dy;
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y >> points[i].c;
    }

    // Предварительно вычисляем квадраты расстояний между всеми парами точек
    vector<vector<long long>> dist(n, vector<long long>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long long d = distSq(points[i], points[j]);
            dist[i][j] = d;
            dist[j][i] = d;
        }
    }

    // Вектор для хранения результатов (количество верных предсказаний для каждого k)
    vector<int> results;

    // Перебираем все нечётные k от 1 до n-1
    for (int k = 1; k < n; k += 2) {
        int correct_count = 0;

        // Для каждой точки выполняем LOO (Leave-One-Out)
        for (int i = 0; i < n; ++i) {
            // Список расстояний от точки i до всех остальных
            vector<pair<long long, int>> neighbors; // (расстояние, индекс)
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    neighbors.push_back({dist[i][j], j});
                }
            }

            // Сортируем по расстоянию
            sort(neighbors.begin(), neighbors.end());

            // Берём k ближайших соседей
            int count_color[2] = {0, 0}; // счётчик цветов: 0 — белый, 1 — чёрный
            for (int idx = 0; idx < k; ++idx) {
                int color = points[neighbors[idx].second].c;
                count_color[color]++;
            }

            // Предсказываем цвет: выбираем тот, что чаще встречается
            int pred_color = (count_color[0] >= count_color[1]) ? 0 : 1;

            // Проверяем, совпадает ли с реальным цветом
            if (pred_color == points[i].c) {
                correct_count++;
            }
        }

        results.push_back(correct_count);
    }

    // Выводим результаты через пробел
    for (int i = 0; i < results.size(); ++i) {
        if (i > 0) cout << " ";
        cout << results[i];
    }
    cout << endl;

    return 0;
}
