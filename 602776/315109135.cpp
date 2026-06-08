#include <bits/stdc++.h>

using namespace std;

int main() {
   
    int cnt = 0;
    long long tmp = 210;
    long long S = 32;
    while(1)
    {
        if(cnt == 3)
            S = tmp;    
        cout << S << " R" << endl;
        int res;
        cin >> res;
        if(res > 0){
            tmp += S;
            cnt = 0;
            S = 32;
        }
        if(res == 0){
            tmp -= S;
            cnt ++;
            S = min(tmp, S * 2);
        }
        if(res == -1 || tmp >= 1000)
        {
            break;
        }
    }
    return 0;
}