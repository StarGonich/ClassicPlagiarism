#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    // Проверяем граничные условия
    if (x != y && abs(x - y) > 100000000) {
        cout << -1;
        return 0;
    }

    // Вычисляем сумму двух неизвестных чисел
    long long sum_ab = 5LL * z - 2LL * x - y;

    long long a, b;
    if (x == y) {
        // Если мода и медиана совпадают
        a = sum_ab / 2;
        b = sum_ab - a;
    } else {
        // Если x != y, избегаем дублирования x
        a = sum_ab - 100000000;
        b = 100000000;
    }

    // Формируем вектор и сортируем
    vector<int> result = {x, x, y, (int)a, (int)b};
    sort(result.begin(), result.end());

    // Проверяем медиану
    if (result[2] != y) {
        cout << -1;
        return 0;
    }

    // Проверяем уникальность моды
    int count_x = 0;
    for (int num : result) {
        if (num == x) count_x++;
    }
    bool unique_mode