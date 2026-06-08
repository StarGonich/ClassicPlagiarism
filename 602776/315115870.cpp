#include <iostream>

using namespace std;

int main(){
    long long n;
    cin >> n;
    long long tempN = n;
    long long k1, k2, k3, k4, k5, k6;
    k4 = n / 4;
    k5 = n/ 5;
    k6 = n / 6;
    long long nn = k4 + k5 + k6;
    //cout << nn << endl;
    while(tempN % 12 != 0){
        tempN--;
    }
    k1 = tempN / 12;
    //cout << k1 << endl;
    tempN = n;
    while(tempN % 20 != 0){
        tempN--;
    }
    k2 = tempN / 20;
    //cout << k2 << endl;
    tempN = n;
    while(tempN % 30 != 0){
        tempN--;
    }
    k3 = tempN / 30;
    //cout << k3 << endl;
    cout << nn - k1 * 2 - k2 * 2 - k3 * 2 + (n / 60 * 2);
}
