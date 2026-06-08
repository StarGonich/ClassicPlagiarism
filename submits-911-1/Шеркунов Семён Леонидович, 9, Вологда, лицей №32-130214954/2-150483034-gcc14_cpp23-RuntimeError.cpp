#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <math.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long summ = 3;
    long long dob = 3;
    vector <long long> num;
    if(n == 2){
        cout << -1;
        return 0;
    }
    if(n == 1){
        cout<<1<<'\n'<<1;
        return 0;
    }
    num.push_back(1);
    num.push_back(2);
    for(int i =2;i<n;i++){
        summ += dob;
        num[i]= dob;
        dob*=2;
    }
    cout << summ <<'\n';
    for(long long i =0;i<n;i++){
        cout << num[i]<<" ";
    }
    return 0;
}
