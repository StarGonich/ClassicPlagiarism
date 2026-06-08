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
    vector<ll> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    if (is_sorted(A.begin(), A.end())) {
        cout << -1;
        return 0;
    }
    if (A[0] == 1 || A[n - 1] == n) {
        int poss = 0, posf = n;
        if (A[0] == 1) {
            while (true) {
                if (poss < n - 1 && A[poss] == A[poss + 1] - 1) {
                    poss++;
                }
                else {
                    poss++;
                    break;
                }
            }
        }
        if (A[n - 1] == n) {
            posf = n - 1;
            while (true) {
                if (posf > 0 && A[posf] == A[posf - 1] + 1) {
                    posf--;
                }
                else {
                    break;
                }
            }
        }
        int posm = 0;
        for (int i = poss; i < posf; i++) {
            if (A[i] == poss + 1) {
                posm = i;
                break;
            }
        }
        if (is_sorted(A.begin() + posm, A.begin() + posf) && is_sorted(A.begin() + poss, A.begin() + posm)) {
            cout << poss + 1 << ' ' << posm - poss << '\n' << posm + 1 <<' ' << posf - posm;
        }
        else {
            cout << -1;
        }

        
    }
    else {
        int poss = 0, posf = n-1;
        while (true) {
            if (poss<n-1 && A[poss] == A[poss + 1]-1) {
                poss++;
            }
            else {
                poss++;
                break;
            }
        }

        while (true) {
            if (posf > 0 && A[posf] == A[posf - 1] + 1) {
                posf--;
            }
            else {
                break;
            }
        }
        if (!is_sorted(A.begin() + poss, A.begin() + posf)) {
            cout << -1;
            return 0;
        }
        for (int i = 0; i < poss; i++) {
            if (A[i] != i + posf + 1) {
                cout << -1;
                return 0;
            }
        }
        for (int i = posf; i < n; i++) {
            if (A[i] != i - posf + 1) {
                cout << -1;
                return 0;
            }
        }

        cout << 1 << ' ' << poss << '\n' << posf + 1 <<' ' << n - posf;
    }
}

