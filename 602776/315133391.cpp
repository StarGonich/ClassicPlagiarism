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
#include <random>

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
    int sum = 210;
    int a;
    int st = 5;
    int cnt = 0;
    srand(rand());
    while (sum < 1000) {
        if (cnt!=3) {
            cout << st << ' ' << ((rand() % 2 == 0) ? 'R' : 'B') << endl;
            cin >> a;
            if (a == 0) {
                sum -= st;
                st *= 2;
                cnt++;
            }
            else if (a == 1) {
                sum += st;
                st = 20;
                cnt = 0;
            }
            else {
                return 0;
            }
        }
        else {
            cnt = 0;
            cout << sum << ' ' << 'R' << endl;
            sum *= 2;
            cin >> a;
            if (a == -1) {
                return 0;
            }
        }
        if (sum < 0) {
            return 0;
        }
        
       // cout << sum << '\n';
    }
    return 0;

    
}

