#include <iostream>
using namespace std;

// Функция проверки, является ли время красивым
bool isBeautiful(int h, int m) {
    int A = h / 10;
    int B = h % 10;
    int C = m / 10;
    int D = m % 10;
    
    // 1) Часы и минуты равны
    if (h == m) return true;
    
    // 2) Зеркальность
    if (A == D && B == C) return true;
    
    // 3) Четыре последовательные цифры
    if (B == A + 1 && C == B + 1 && D == C + 1) return true;
    
    return false;
}

int main() {
    int h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;
    
    int count = 0;
    int h = h1, m = m1;
    
    // Перебираем все моменты времени от (h1, m1) до (h2, m2) включительно
    while (true) {
        if (isBeautiful(h, m)) {
            count++;
        }
        
        // Если дошли до конечного момента, выходим
        if (h == h2 && m == m2) {
            break;
        }
        
        // Увеличиваем время на 1 минуту
        m++;
        if (m == 60) {
            m = 0;
            h++;
            if (h == 24) {
                h = 0;
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}