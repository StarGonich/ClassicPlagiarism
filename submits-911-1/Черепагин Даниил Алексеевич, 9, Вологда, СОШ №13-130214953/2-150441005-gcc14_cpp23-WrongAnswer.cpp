#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    if (n == 1) {
        cout << "1\n1\n";
        return 0;
    }
    
    // Используем число 2^(n-1) * 3
    long long m = (1LL << (n - 1)) * 3;
    vector<long long> divisors;
    
    // Добавляем степени двойки: 1, 2, 4, ..., 2^(n-2)
    for (int i = 0; i < n - 1; i++) {
        divisors.push_back(1LL << i);
    }
    
    // Последний делитель: 3 * 2^(n-2)
    divisors.push_back(3 * (1LL << (n - 2)));
    
    cout << m << endl;
    for (long long d : divisors) {
        cout << d << " ";
    }
    cout << endl;
    
    return 0;
}