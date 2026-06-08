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

int main()
{

    ll bank = 210;
    ll k = 0;
    int bet = 0;
    int curLose = 0;
    int diler = 0;
    int sumBets = 0;
    char curColor = 'B';
    while(bank < 1000 && k <= 100){
        if(curLose == 0){
            bet = 10;
            if(bank < 10){
                bet = bank;
            }
            sumBets += bet;
        }else if(curLose == 1){
            bet = 3*sumBets;
            if(bank < bet){
                bet = bank;
            }
            sumBets += bet;
        }else if(curLose == 2){
            bet = sumBets + 10;
            if(bank < bet){
                bet = bank;
            }
            sumBets += bet;
        }else if(curLose == 3){
            bet = bank;
            sumBets = 0;
        }

        cout << bet << " " << curColor << endl;
        cout << flush;

        cin >> diler;
        if(diler == 0){
            bank -= bet;
            curLose++;
        }else if(diler == 1){
            bank += bet;
            curLose = 0;
            sumBets = 0;
        }else{
            return 0;
        }
        k++;
        //cout << bank << "\n";
    }
    return 0;


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

    ll n;
    cin >> n;
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
    cout << k;



    ll a, b, p;
    cin >> a >> b >> p;
    ll c, d, 1;
    cin >> c >> d >> q;
    */




}
