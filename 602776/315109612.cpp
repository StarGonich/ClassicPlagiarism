#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <iomanip>
#include <set>
#include <unordered_set>
#include <map>
#include <cmath>
#include <algorithm>

#define ll long long
#define ld long double

using namespace std;

//vector<ll> T(1e6 + 4,0);
//
//
//void update(int ind, ll val) { // ind - list
//    T[ind] = val;
//    int tmp = 0;
//    while (ind != 1) {
//        tmp++;
//        ind /= 2;
//        T[ind] = T[ind * 2] + T[ind * 2 + 1];
//    }
//
//}
//long long Sum_Tree(int ind,int lt,int rt,int l,int r) { // ind - 1 Корень,  
//    if (rt <= l || r <= lt) {
//        return 0;
//    }
//    if (l <= lt && rt <= r) {
//        return T[ind];
//    }
//    int m = (rt + lt) / 2;
//    return Sum_Tree(ind * 2, lt, m, l, r) + Sum_Tree(ind * 2 + 1, m, rt, l, r);
//}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> A(n), D(n);
    vector<bool> Used(n, 0);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> D[i];
    ll k;
    cin >> k;
    --k;
    ll anw = 1;
    int i, j;
    Used[k] = true;
    ll mn=1e15, mx = -1e15;
    ll pmn=k, pmx=k;
    bool end = false;
    ll cnt = 0;
    while (!end) {
        ++cnt;
        if (cnt > 1e6) {
            return 12;
        }
        end = true;
        int i1 = upper_bound(A.begin(), A.end(), A[pmx] + D[pmx]) - A.begin() - 1;
        int j1 = lower_bound(A.begin(), A.end(), A[pmn] - D[pmn]) - A.begin();
        mn = 1e15;
        mx = -1e15;

        for (int i = j1; i <= i1; ++i) {
            end &= Used[i];
            if (!Used[i]) {
                ++anw;
            }
            Used[i] = true;
            
            if (A[i] + D[i] > mx) {
                mx = A[i] + D[i];
                pmx = i;
            }
            if (A[i] - D[i] < mn) {
                mn = A[i] - D[i];
                pmn = i;
            }
        }
    }
    cout << anw;
    

}

