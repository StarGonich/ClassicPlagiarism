#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<vector<int>> Field;

int n, m, k;
vector<Field> configurations;

// Проверка, могла ли конфигурация prev предшествовать curr
bool isPrevious(const Field &prev, const Field &curr) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int live_neighbors = 0;
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    if (di == 0 && dj == 0) continue;
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        live_neighbors += prev[ni][nj];
                    }
                }
            }

            int expected = curr[i][j];
            int prev_state = prev[i][j];

            // Правило для живой клетки
            if (prev_state == 1) {
                if (live_neighbors == 2 || live_neighbors == 3) {
                    if (expected != 1) return false; // должно остаться живой
                } else {
                    if (expected != 0) return false; // должна погибнуть
                }
            } else {
                // Мертвая клетка
                if (live_neighbors == 3) {
                    if (expected != 1) return false; // должна ожить
                } else {
                    if (expected != 0) return false; // останется мертвой
                }
            }
        }
    }
    return true;
}

int main() {
    cin >> k;
    cin >> n >> m;

    configurations.resize(k);
    for (int i = 0; i < k; ++i) {
        configurations[i].resize(n, vector<int>(m));
        for (int r = 0; r < n; ++r)
            for (int c = 0; c < m; ++c)
                cin >> configurations[i][r][c];
    }

    // Предположим, что последняя по порядку - стабильноая конфигурация
    vector<int> order(k);
    for (int i = 0; i < k; ++i) order[i] = i;

    vector<int> result;
    int current_idx = order.back(); // начинаем с последней (финальной)
    result.push_back(current_idx);

    // Восстанавливаем последовательность назад
    for (int step = 0; step < k - 1; ++step) {
        bool found_prev = false;
        for (int i = 0; i < k; ++i) {
            if (i == current_idx) continue;
            if (isPrevious(configurations[i], configurations[current_idx])) {
                current_idx = i;
                result.push_back(i);
                found_prev = true;
                break;
            }
        }
        if (!found_prev) {
            // Если не нашли, значит текущая - исходная
            break;
        }
    }

    // Переворачиваем последовательность, чтобы она была в правильном порядке
    reverse(result.begin(), result.end());

    // Выводим номера конфигураций (от 1 до k)
    for (auto &idx : result) {
        cout << (idx + 1) << " ";
    }
    cout << "\n";

    return 0;
}