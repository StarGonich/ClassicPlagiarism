#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Функция для проверки, является ли число совершенным
bool isPerfect(long long num, int n, vector<long long>& divisors) {
    vector<long long> temp;
    long long sum = 1;  // 1 всегда делитель
    temp.push_back(1);
    
    for (long long i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            sum += i;
            temp.push_back(i);
            if (i != num / i) {
                sum += num / i;
                temp.push_back(num / i);
            }
        }
    }
    
    if (sum == num && temp.size() >= n) {
        // Берем первые n делителей
        for (int i = 0; i < n; i++) {
            divisors.push_back(temp[i]);
        }
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    
    // Известные совершенные числа в диапазоне до 10^9
    vector<long long> perfectNumbers = {6, 28, 496, 8128, 33550336};
    
    for (long long num : perfectNumbers) {
        vector<long long> divisors;
        if (isPerfect(num, n, divisors)) {
            cout << num << endl;
            for (long long d : divisors) {
                cout << d << " ";
            }
            cout << endl;
            return 0;
        }
    }
    
    // Если не нашли совершенное число, используем другой подход
    // Для n = 1: любое число подходит
    if (n == 1) {
        cout << "1" << endl;
        cout << "1" << endl;
        return 0;
    }
    
    // Для n = 2: используем числа вида p + 1, где p - простое
    if (n == 2) {
        cout << "3" << endl;
        cout << "1 2" << endl;
        return 0;
    }
    
    // Для других случаев используем числа вида 2^k
    // У числа 2^k делители: 1, 2, 4, ..., 2^(k-1), 2^k
    // Их сумма: 1 + 2 + 4 + ... + 2^(k-1) = 2^k - 1
    // Если взять все кроме последнего, получим 2^k - 1
    
    // Найдем минимальное k такое, что 2^k - 1 >= n
    int k = 1;
    while ((1LL << k) - 1 < n) {
        k++;
    }
    
    long long m = 1LL << k;  // 2^k
    vector<long long> divisors;
    
    // Добавляем степени двойки до тех пор, пока не наберем n делителей
    long long current = 1;
    for (int i = 0; i < n - 1; i++) {
        divisors.push_back(current);
        current *= 2;
    }
    // Последний делитель - само число минус сумма уже выбранных
    long long sum = 0;
    for (long long d : divisors) {
        sum += d;
    }
    divisors.push_back(m - sum);
    
    cout << m << endl;
    for (long long d : divisors) {
        cout << d << " ";
    }
    cout << endl;
    
    return 0;
}