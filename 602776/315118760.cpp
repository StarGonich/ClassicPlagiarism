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
    int poss = 0, posf = n;
    if (A[poss] == 1) {
        while (true) {
            if (poss<n-1 &&  A[poss + 1] - A[poss] == 1) {
                poss++;
            }
            else {
                poss++;
                break;
            }
        }
    }
    if (poss == n) {
        cout << -1;
        return 0;
    }
    if (A[posf-1] == n) {
        posf = n - 1;
        while (true) {
            if (A[posf] - A[posf-1] == 1) {
                posf--;
            }
            else {
                break;
            }
        }
    }
    ll posm = 0;
    vector<ll> Tmp1,Tmp2;
    Tmp1.reserve(n);
    Tmp1.push_back(A[poss]);
    for (int i = poss+1; i < posf; i++) {
        Tmp1.push_back(A[i]);
        if (A[i] < A[i - 1]) {
            posm = i;
            break;
        }
    }
    for (int i = posm; i < posf; i++) {
        Tmp2.push_back(A[i]);
    }
    Tmp1.pop_back();
    bool anw = true;
    for (int i = 0; i < Tmp2.size(); i++) {
        if (Tmp2[i] != i + poss+1) {
            anw = false;
            //cout << -1 << '\n';
            break;
        }
    }
    for (int i = 0; i < Tmp1.size(); i++) {
        if (Tmp1[i] != i + posm) {
            anw = false;
            //cout << -1 << '\n';
            break;
        }
    }
    if (anw) {
        cout << poss + 1 << ' ' << Tmp1.size() << '\n' << posm + 1 << ' ' << Tmp2.size();
        return 0;
    }


    if (!anw) {
        anw = true;
        poss = 0;
        while (true) {
            if (poss < n - 1 && A[poss + 1] - A[poss] == 1) {
                poss++;
            }
            else {
                poss++;
                break;
            }
        }

        posf = n - 1;
        while (true) {
            if (A[posf] - A[posf - 1] == 1) {
                posf--;
            }
            else {
                --posf;
                break;
            }
        }

        for (int i = posf + 1; i < n; i++) {
            if (A[i] != i - posf) {
                anw = false;
                break;
            }
        }
        for (int i = 0; i < poss; i++) {
            if (A[i] != n+i-poss+1) {
                anw = false;
                break;
            }
        }
        if (!is_sorted(A.begin() + poss, A.begin() + posf + 1)) {
            anw = false;
        }




    }

    if (anw) {
        cout << 1 << ' ' <<poss<<'\n'<<posf+2<<' '<<n-posf-1;
    }
    else {
        cout << -1;
    }
}

