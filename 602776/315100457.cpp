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
    ll anw1 = 0,anw2=0,anw3=0;
    cin >> n;
    ll anw = n / 4 + n / 5 + n / 6 - n / 20 - n / 12 - n / 30 + n / 60 - 1;
    cout << anw;

}

