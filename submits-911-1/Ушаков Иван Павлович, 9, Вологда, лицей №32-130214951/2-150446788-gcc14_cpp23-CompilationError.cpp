#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int main()
{
    vector <int> num;
    num.push_back(0);
    num.push_back(1);
    num.push_back(-1);
    num.push_back(6);
    for(int i=4; i<=30; i++){
        num.push_back(num[i-1]*2);
    }
    int n;
    cin >> n;
    cout << num[n] << endl;
    if(n==2){
        return 0;
    }
    if(n==1){
        cout << 1;
    }
    else if(n>=3){
        cout << 1 << " " << 2 << " " << 3 << " ";
        for(int i=3; i<n; ++i){
            cout << num[i] << " ";
        }
    
    return 0;
    
}
