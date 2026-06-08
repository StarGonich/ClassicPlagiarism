#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll binSearch(vector<ll> a, ll val){
    ll l = -1;
    ll r = a.size();
    while(l < r - 1){
        ll m = (l + r)/2;
        if(a[m] < val){
            l = m + 1;
        }else{
            r = m;
        }
    }
    return r;
}

double f(double m){

    return 0;
}

double ternarySearch(double l, double r, double eps){
    while(r - l >= eps){
        double m1 = l + (r - l)/3;
        double m2 = r - (r - l)/3;
        if(f(m1) < f(m2)){
            l = m1;
        } else{
            r = m2;
        }
    }

    return (l + r)/2;
}

vector<bool> explosed(1e5, false);

void rec(ll k, vector<ll>& x, vector<ll>& d){
    for(int i = 0; i < x.size(); i++){
        if(!explosed[i] && ((x[i] >= x[k] - d[k]) && x[i] <= x[k] + d[k])){
            explosed[i] = true;
            rec(i, x, d);
        }
    }
}

int main()
{
    ll bank = 210;
    ll k = 0;
    int bet = 0;
    int curLose = 0;
    int diler;
    int sumBets = 0;
    char curColor = 'B';
    while(bank < 1000 && k <= 100){
        if(curLose == 0){
            bet = 10;
            sumBets += bet;
        }else if(curLose == 1){
            bet = 3*sumBets;
            sumBets += bet;
        }else if(curLose == 2){
            bet = sumBets;
            sumBets += bet;
        }else if(curLose == 3){
            bet = bank;
            sumBets = 0;
        }

        cout << bet <<" " << curColor;
        cout << endl << flush;

        cin >> diler;
        if(diler == 0){
            bank -= bet;
            curLose++;
        }else if(diler == 1){
            bank += bet;
            curColor = 'R';
            curLose = 0;
            sumBets = 0;
        }else{
            return 0;
        }
        k++;
    }



    /*
    ll n;
    cin >> n;

    vector<ll> x(n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    vector<ll> d(n);
    for(int i = 0; i < n; i++){
        cin >> d[i];
    }

    ll k;
    cin >> k;
    k--;
    explosed[k] = true;
    rec(k, x, d);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(explosed[i]){
            ans++;
        }
    }
    cout << ans;
    */
    /*
    ll k = 0;
    for(int i = 4; i <= n; i++){
        if(i % 4 == 0 && i % 5 != 0 && i % 6 != 0){
            k++;
        }else if(i % 4 != 0 && i % 5 == 0 && i % 6 != 0){
            k++;
        }
        else if(i % 4 != 0 && i % 5 != 0 && i % 6 == 0){
            k++;
        }
    }
    */

    /*
    ll a, b, p;
    cin >> a >> b >> p;
    ll c, d, 1;
    cin >> c >> d >> q;
    */




}
