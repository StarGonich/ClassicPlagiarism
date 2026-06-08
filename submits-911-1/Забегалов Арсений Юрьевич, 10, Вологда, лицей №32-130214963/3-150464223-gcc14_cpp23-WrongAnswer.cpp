#include <algorithm>
#include <iostream>
#include <climits>
#include <utility>
#include <cstdio>
#include <vector>
#include <set>
#include <map>


using namespace std;
using ll = long long;
using str = string;

#define matrix vector<vector<ll>>
#define f first
#define s second

vector<pair<ll, ll>> q;

ll find_time(ll start_pos, ll ind, ll n){
    ll pos = start_pos+3600;
    ll cur_ad = 0;
    while(ind < n && q[ind].s<pos){
        cur_ad+=(q[ind].s - q[ind].f);
        ind++;
    }
    if(ind < n && q[ind].f < pos){
        cur_ad+=pos-q[ind].f;
    }
    return cur_ad;
}

ll normalize_pos(ll pos, ll n){
    ll l = -1, r = n;
    while(l+1!=r){
        ll m = (l+r)/2;
        //cout << m << endl;
        if(q[m].s > pos){
            r = m;
        }
        else{
            l = m;
        }
    }
    if(q[r].f>pos+3600){
        return 0;
    }
    ll end_pos = pos+3600;
    ll cur_ad = 0;
    while(r < n && q[r].s<end_pos){
        cur_ad += q[r].s - q[r].f;
        r++;
    }
    if(r<n && q[r].f < end_pos){
        cur_ad+=end_pos-q[r].f;
    }
    return cur_ad;

}

int main()
{
    ll n, t;
    cin >> n >> t;
    q.resize(n);
    for(ll i = 0;i<n;i++){
        cin >> q[i].f >> q[i].s;
    }
    ll time = 0, pos = 0;
    for(ll i = 0;i<n;i++){
        pos = q[i].f;
        time = find_time(pos, i, n);
        if(time>t){
            ll l = max(q[i].f-3601, 0LL),  r = q[i].f+3601;
            while(l+1!=r){
                ll m = (l+r)/2;
                if(normalize_pos(m, n) > t){
                    r = m;
                }
                else{
                    l = m;
                }
            }
            cout << r;
            return 0;
        }
    }
    cout << -1;
}
