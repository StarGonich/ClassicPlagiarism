#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if(n == 1){
        cout << "1\n1";
        return 0;
    }
    if(n == 2){
        cout << "-1";
        return 0;
    }
    n++;
    vector<int>v(n);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    for(int i = 3; i < n; i++){
        v[i] = v[i - 1] << 1;
    }
    n--;
    cout << v[n] << '\n';
    for(int i = 0; i < n; i++){
        cout << v[i] << ' ';
    }
    return 0;
}
