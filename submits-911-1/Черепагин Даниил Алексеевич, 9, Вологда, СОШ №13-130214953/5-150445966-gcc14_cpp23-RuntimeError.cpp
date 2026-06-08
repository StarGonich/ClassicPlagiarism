#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

// Функция для подсчета живых соседей
int countLiveNeighbors(const vector<vector<int>>& grid, int x, int y, int n, int m) {
    int count = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;
            
            int nx = x + dx;
            int ny = y + dy;
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                count++;
            }
        }
    }
    return count;
}

// Функция для выполнения одного шага игры
vector<vector<int>> nextGeneration(const vector<vector<int>>& grid, int n, int m) {
    vector<vector<int>> newGrid(n, vector<int>(m, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int liveNeighbors = countLiveNeighbors(grid, i, j, n, m);
            
            if (grid[i][j] == 1) {
                // Живая клетка
                if (liveNeighbors == 2 || liveNeighbors == 3) {
                    newGrid[i][j] = 1;
                }
            } else {
                // Мертвая клетка
                if (liveNeighbors == 3) {
                    newGrid[i][j] = 1;
                }
            }
        }
    }
    
    return newGrid;
}

// Функция для сравнения двух конфигураций
bool areEqual(const vector<vector<int>>& a, const vector<vector<int>>& b, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != b[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int k, n, m;
    cin >> k >> n >> m;
    
    vector<vector<vector<int>>> configs(k, vector<vector<int>>(n, vector<int>(m)));
    
    // Чтение конфигураций
    for (int idx = 0; idx < k; idx++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> configs[idx][i][j];
            }
        }
    }
    
    // Найдем стабильную конфигурацию (все мертвые клетки)
    int stableConfig = -1;
    for (int i = 0; i < k; i++) {
        bool allDead = true;
        for (int x = 0; x < n && allDead; x++) {
            for (int y = 0; y < m && allDead; y++) {
                if (configs[i][x][y] == 1) {
                    allDead = false;
                }
            }
        }
        if (allDead) {
            stableConfig = i;
            break;
        }
    }
    
    // Будем моделировать игру от каждой конфигурации, пока не найдем путь к стабильной
    vector<int> result(k);
    vector<bool> used(k, false);
    
    // Стабильная конфигурация - последняя
    result[k-1] = stableConfig + 1;
    used[stableConfig] = true;
    
    // Начинаем с конца и идем к началу
    vector<vector<int>> current = configs[stableConfig];
    
    for (int pos = k-2; pos >= 0; pos--) {
        // Ищем конфигурацию, которая является предыдущей для current
        for (int i = 0; i < k; i++) {
            if (used[i]) continue;
            
            vector<vector<int>> next = nextGeneration(configs[i], n, m);
            if (areEqual(next, current, n, m)) {
                result[pos] = i + 1;
                used[i] = true;
                current = configs[i];
                break;
            }
        }
    }
    
    // Выводим результат
    for (int i = 0; i < k; i++) {
        cout << result[i];
        if (i < k-1) cout << " ";
    }
    cout << endl;
    
    return 0;
}