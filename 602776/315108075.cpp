#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <set>
#include <cmath>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <map>
#include <fstream>
#include <deque>
#include <random>
#include <time.h>
#include<ctime>
#include <stdlib.h>
#define int  long long 
using namespace std;
//int mod = 1e9 + 7;
int mod = 998244353;
int gmod = 100000000000031;
int pp = 37;
double eps = 1e-8;
int inf = 1e16;
const double pi = acos(-1);
string abc = "abcdefghijklmnopqrstuvwxyz", a123 = "0123456789";
vector<vector<double>> e(5, vector<double>(5));

vector<vector<double>> mult_matr(vector<vector<double>> A, vector<vector<double>>B) {
    vector<vector<double>> res = A;
    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < A.size(); j++) {
            res[i][j] = 0;
            for (int h = 0; h < A.size(); h++)
                res[i][j] += A[i][h] * B[h][j];
        }

    return res;
}

vector<vector<double>> bpow_m(vector<vector<double>>num, int pow) {
    if (pow == 0)
        return e;
    if (pow == 1)
        return num;
    if (pow % 2 != 0)
        return mult_matr(num, bpow_m(num, pow - 1));
    vector<vector<double>> qq = bpow_m(num, pow / 2);
    return mult_matr(qq, qq);
}

int bpow(int num, int pow) {
    if (pow == 0)
        return 1ll;
    if (pow == 1)
        return num;
    if (pow % 2 != 0)
        return (num * bpow(num, pow - 1)) % mod;
    int qq = bpow(num, pow / 2);
    return (qq * qq) % mod;
}
int bpow_mod(int num, int pow, int mod1) {
    if (pow == 0)
        return 1ll;
    if (pow == 1)
        return num;
    if (pow % 2 != 0)
        return (num * bpow_mod(num, pow - 1, mod1)) % mod1;
    int qq = bpow_mod(num, pow / 2, mod1);
    return (qq * qq) % mod1;
}
double bpow1(double num, int pow) {
    if (pow == 0)
        return 1;
    if (pow == 1)
        return num;
    if (pow % 2 != 0)
        return num * bpow1(num, pow - 1);
    double qq = bpow1(num, pow / 2);
    return qq * qq;
}
int gcd(int a, int b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    while (a % b != 0 && b % a != 0) {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return min(a, b);
}

int find_per(vector<int>& v, int pos) {
    int per, buf = pos;
    while (buf != v[buf])
        buf = v[buf];
    per = buf;
    while (pos != v[pos]) {
        buf = v[pos];
        v[pos] = per;
        pos = buf;
    }
    return per;
}



struct SegmentTree {
    vector<int> tree;
    vector<int> lazy;
    int n;


    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

    void apply(int v, int tl, int tr) {
        if (lazy[v] != 0) {
            tree[v] += lazy[v] * (tr - tl + 1);
            if (tl != tr) {
                lazy[v * 2] += lazy[v];
                lazy[v * 2 + 1] += lazy[v];
            }
            lazy[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, int val) {
        apply(v, tl, tr);

        if (l > r) return;
        if (l == tl && r == tr) {
            lazy[v] += val;
            apply(v, tl, tr);
        }
        else {
            int tm = (tl + tr) / 2;
            update(v * 2, tl, tm, l, min(r, tm), val);
            update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }
    }


    int query(int v, int tl, int tr, int l, int r) {
        apply(v, tl, tr);          if (l > r) return 0;
        if (l == tl && r == tr) {
            return tree[v];
        }
        else {
            int tm = (tl + tr) / 2;
            return query(v * 2, tl, tm, l, min(r, tm)) +
                query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        }
    }
};

void update_range(SegmentTree& st, int l, int r, int val) {
    st.update(1, 0, st.n - 1, l, r, val);
}

int range_sum(SegmentTree& st, int l, int r) {
    return st.query(1, 0, st.n - 1, l, r);
}
int check(vector<int>&v, vector<pair<int, int>>& lr, vector<int> pp) {
    vector<int> buf;
    for (int i = 0; i < pp.size(); i++)
    {
        int  bpos=lr[i].first;
        while (bpos < lr[i].second) {

            buf.push_back(v[bpos]);
            bpos++;
        }
    }
    for (int i = 0; i < v.size(); i++)
        if (v[i] != i + 1)
            return 0;
    return 1;
}

int32_t   main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n=210;
    
    int fl = 0;
    while (n < 1000) {
        if (fl == 0) {
            cout << 30<<' '<<'R' << endl;
            int x;
            cin >> x;
            if (x == 1)
                n += 30;
            else
            {
                n -= 30;
                fl = 1;
            }
            continue;
        }
        if (fl == 1) {
            cout << 60 << ' ' << 'R' << endl;
            int x;
            cin >> x;
            if (x == 1) {
                n += 60;
                fl = 0;
            }
            else
            {
                n -= 60;
                fl++;
            }
            continue;
        }
        if (fl == 2) {
            cout << n << ' ' << 'R' << endl;
            int x;
            cin >> x;
            if (x == 1) {
                n += n;
                fl = 0;
            }
            continue;
        }
    }
}