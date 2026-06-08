#include <iostream>
#include <vector>
using namespace std;
int lcm(int a, int b) {
    int a1 = a, b1 = b;
    if (a1 < b1) {
        swap(a1, b1);
    }
    while (a1 % b1 != 0) {
        a1 = a1 % b1;
        swap(a1, b1);
    }
    return (a * b / b1);
}
int gcd(int a, int b) {
    int a1 = a, b1 = b;
    if (a1 < b1) {
        swap(a1, b1);
    }
    while (a1 % b1 != 0) {
        a1 = a1 % b1;
        swap(a1, b1);
    }
    return (b1);
}
int main()
{
   long long n, k, p;
   long long mini = lcm(n, n + 1);
   cin >> n >> k;
   for (long long i = n + 1; i <= n + k; i++) {
        if (gcd(n, i) == n) {
            p = i;
            break;
        }
        if (lcm(n,i) < mini) {
            mini = lcm(n,i);
            p = i;
        }
   }
   cout << p;
}
