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
    int summ = 3;
    int dob = 3;
    vector <int> num(n);
    if(n == 2){
        cout << -1;
        return 0;
    }
    if(n == 1){
        cout<<1<<'\n'<<1;
        return 0;
    }
    num[0]=1;
    num[1]=2;
    for(int i =2;i<n;i++){
        summ += dob;
        num[i]= dob;
        dob*=2;
    }
    cout << summ<<'\n';
    for(int i =0;i<n;i++){
        cout << num[i]<<" ";
    }
    return 0;
}

