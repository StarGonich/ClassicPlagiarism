#include <bits/stdc++.h>

using namespace std;

int main() {
   
    int cnt = 0;
    long long tmp = 210;
    long long S = 2;
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
            int x = 1;
            while((x*2) * 15 < tmp) x*=2;
            S = x;
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