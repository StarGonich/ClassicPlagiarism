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
    ld a, b, p, c, d, q;
    cin >> a >> b >> p;
    cin >> c >> d >> q;
    if (a != 0) {
        if (b * c / a == d && p * c / a == q) {
            cout << "Ambiguity";
            return 0;
        }
        if ((b * c / a == d && p * c / a != q) || ((b * c / a != d && p * c / a == q))) {
            cout << "Contradiction";
            return 0;
        }
    }
    else if (b != 0) {
        if (c==0 && p * b / d == q) {
            cout << "Ambiguity";
            return 0;
        }
        if ((c == 0 && p * b / d != q) || ((c != 0 && p * b / d == q))) {
            cout << "Contradiction";
            return 0;
        }
    }
    else {
        cout << "Contradiction";
        return 0;
    }
    if (d != 0) {
        ld x = (p - b * q / d) / (a - b * c / d);
        ld y = (q - c * x) / d;
        if (x <= 0 || y <= 0) {
            cout << "Not positive";
            return 0;
        }
        cout << "Success\n" << fixed << setprecision(4) << x * 100 << ' ' << y * 100;
    }
    else if(c!=0){
        ld y = (p-q*a/c)/(b - a * d / c);
        ld x = (q - d * y) / c;
        if (x <= 0 || y <= 0) {
            cout << "Not positive";
            return 0;
        }
        cout << "Success\n" << fixed << setprecision(4) << x * 100 << ' ' << y * 100;
    }
    else {
        cout << "Contradiction";
        return 0;
    }
    

}

