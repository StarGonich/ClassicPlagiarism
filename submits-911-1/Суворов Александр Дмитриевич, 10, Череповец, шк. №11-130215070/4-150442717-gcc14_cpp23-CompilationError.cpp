#include <algorithm>
using namespace std;
int gcm(int num1,int num2) {
    int i = 2;
    while (i<=min(num1,num2)) {
        if (num1 % i == 0 && num2 % i == 0) {
            return i;
        }
        i++;
        

}
    return 0;
}
int nok(long long n,long long k) {
    long long num = 0ll;
    for (int i = n + 1; i <= n + k; i++) {
        num = gcm(i, n);
        if (num != 0) {
            return i;
        }
    }
}
int main()
{
    long long n,k,num=0;
    cin >> n >> k;
    cout << nok(n, k);
    
}