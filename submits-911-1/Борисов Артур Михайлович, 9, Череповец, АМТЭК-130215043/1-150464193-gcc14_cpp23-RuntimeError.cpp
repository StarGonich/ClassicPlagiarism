#include <iostream>
#include <vector>
using namespace std;
int lcmm(int a, int b) {
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
int gcdd(int a, int b) {
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
   long long mini = lcmm(n, n + 1);
   cin >> n >> k;
   for (long long i = n + 1; i <= n + k; i++) {
        if (gcdd(n, i) == n) {
            p = i;
            break;
        }
        if (lcmm(n,i) < mini) {
            mini = lcmm(n,i);
            p = i;
        }
   }
   cout << p;
   return 0;
}
