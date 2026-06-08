#include <bits/stdc++.h>

using namespace std;

int main() {
   
    int cnt = 0;
    long long tmp = 210;
    long long S = 1;
    while((S*2) * 15 <= tmp) S*=2;
    S = min(S, tmp);
    
    int M = 0;
    while(1)
    {
        M ++;
        //if(cnt == 3)
        //    S = tmp;    
        cout << S << " R" << endl;
        int res;
        cin >> res;
        if(res  == 1){
            tmp += S;
            cnt = 0;
            long long x = 1;
            while((x*2) * 15 <= tmp) x*=2;
            S = min(x, tmp);
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
        if(M == 100)
            break;
    }
    assert(tmp >= 1000);
    return 0;
}