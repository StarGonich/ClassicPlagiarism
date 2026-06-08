cpp
#include <iostream>
#include <algorithm>
using namespace std;

// Функция для вычисления НОД (Алгоритм Евклида)
long long gcdLL(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    long long n, k;
    cin >> n >> k;

    long long min_lcm = LLONG_MAX;
    long long answer_p = n + 1;

    for (long long p = n + 1; p <= n + k; ++p) {
        long long g = gcdLL(n, p);
        // Вычисление НОК без переполнения
        long long lcm = (n / g) * p;
        if (lcm < min_lcm) {
            min_lcm = lcm;
            answer_p = p;
        }
    }

    cout << answer_p << "\n";

    return 0;
}