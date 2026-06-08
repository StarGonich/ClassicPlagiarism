#include<iostream>
#include<deque>
using namespace std;
struct pairlr{
    long long l, r;
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, T, notrec = 0, ans;
    pairlr now;
    cin >> n >> T >> now.l >> now.r;
    if(T >= 3600){
        cout << "-1";
        return 0;
    }
    if(now.r - now.l > T){
        cout << max(0ll, now.l + T - 3600 + 2);
        return 0;
    }
    deque<pairlr>d = {now};
    for(int i = 1; i < n; i++){
        cin >> now.l >> now.r;
        notrec += now.l - d.back().r;
        d.push_back(now);
        while(d.front().r + 3600 <= d.back().r){
            notrec += d.front().r;
            d.pop_front();
            notrec -= d.front().l;
        }
        if(d.back().r - d.front().l - notrec > T){
            ans = d.back().r - 3600;
            ans -= d.back().r - d.front().l - notrec - T;
            cout << max(ans + 1, 0ll);
            return 0;
        }
    }
    cout << "-1";
    return 0;
}
