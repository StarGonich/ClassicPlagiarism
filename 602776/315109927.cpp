#include <iostream>

using namespace std;

int main(){
    long long n;
    cin >> n;
    long long tempN = n;
    long long k1, k2, k3;
    while(tempN % 12 != 0){
        n--;
    }
    k1 = tempN / 12;

    tempN = n
    while(tempN % 20 != 0){
        n--;
    }
    k2 = tempN / 20;

    tempN = n;
    while(tempN % 30 != 0){
        n--;
    }
    k3 = tempN / 30;

    cout << n - k1 - k2- k3 + (n / 60 * 2);
}
