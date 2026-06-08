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
//#define int  long long 
using namespace std;
int mod = 1e9 + 7;
//int mod = 998244353;
int gmod = 100000000000031;
int pp = 37;
double eps = 1e-8;
int inf = 1e16;
const double pi = acos(-1);
//string abc = "abcdefghijklmnopqrstuvwxyz", a123 = "0123456789";
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
int check(vector<int>& v, vector<pair<int, int>>& lr, vector<int> pp) {
    vector<int> buf;
    for (int i = 0; i < pp.size(); i++)
    {
        int  bpos = lr[i].first;
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
bool buf[22][22];
void press(int i, int j) {
    buf[i][j] = !buf[i][j];
    buf[i - 1][j] = !buf[i - 1][j];
    buf[i + 1][j] = !buf[i + 1][j];
    buf[i][j - 1] = !buf[i][j - 1];
    buf[i][j + 1] = !buf[i][j + 1];
}
void change(vector<int>& rr, int k, int& res) {

    for (int i = 0; i < rr.size(); i++)
    {
        res += k % 2;
        rr[i] = k % 2;
        k /= 2;
    }
    for (int i = 0; i < rr.size(); i++)
        if (rr[i] == 1)
            press(1, i + 1);
}
void press1(int i, int j) {
    cout << i << ' ' << j << '\n';
    buf[i][j] = !buf[i][j];
    buf[i - 1][j] = !buf[i - 1][j];
    buf[i + 1][j] = !buf[i + 1][j];
    buf[i][j - 1] = !buf[i][j - 1];
    buf[i][j + 1] = !buf[i][j + 1];
}
void change1(vector<int>& rr, int k, int& res) {

    for (int i = 0; i < rr.size(); i++)
    {
        res += k % 2;
        rr[i] = k % 2;
        k /= 2;
    }
    for (int i = 0; i < rr.size(); i++)
        if (rr[i] == 1)
            press1(1, i + 1);
}
void copy(vector<vector<bool>>& mm) {
    for (int i = 0; i < mm.size(); i++)
        for (int j = 0; j < mm[i].size(); j++)
            buf[i][j] = mm[i][j];
}
int32_t   main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<char>> matrix(n + 2, vector<char>(n + 2));
    vector<vector<bool>> mm(n + 2, vector<bool>(n + 2)), un(n + 2, vector<bool>(n + 2));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> matrix[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (matrix[i][j] == 'b')
                mm[i][j] = true;
            else
                mm[i][j] = false;
            un[i][j] = !mm[i][j];
        }

    int res = inf, ind = -1, res_un = inf, ind_un = -1;
    vector<int> rr(matrix.size() - 2);

    int qqq = (1ll << min(n-5,15));
    long long count = 0;
    for (int i = 0; i < qqq; i++) {
        int ww = rand();
        copy(mm);
        int buf_res = 0;
        change(rr, ww, buf_res);
        for (int j = 2; j <= n; ++j)
            for (int h = 1; h <= n; ++h)
                if (buf[j - 1][h] == 1) {
                    buf_res++;
                    buf[j][h] = !buf[j][h];
                    buf[j - 1][h] = !buf[j - 1][h];
                    buf[j + 1][h] = !buf[j + 1][h];
                    buf[j][h - 1] = !buf[j][h - 1];
                    buf[j][h + 1] = !buf[j][h + 1];
                    count += 1;
                }
        int fl = 1;
        for (int j = 1; j <= n; j++)
            if (fl == 0)
                break;
            else
                for (int h = 1; h <= n; h++)
                    if (buf[j][h] == 1)
                        fl = 0;
        if (fl) {
            if (res > buf_res) {
                res = buf_res;
                ind = ww;
            }
        }
    }

    for (int i = 0; i < qqq; i++) {
        int ww = rand();
        copy(un);
        int buf_res = 0;
        change(rr, ww, buf_res);
        for (int j = 2; j <= n; ++j)
            for (int h = 1; h <= n; ++h)
                if (buf[j - 1][h] == 1) {
                    buf_res++;
                    buf[j][h] = !buf[j][h];
                    buf[j - 1][h] = !buf[j - 1][h];
                    buf[j + 1][h] = !buf[j + 1][h];
                    buf[j][h - 1] = !buf[j][h - 1];
                    buf[j][h + 1] = !buf[j][h + 1];
                    count += 1;
                }
        int fl = 1;
        for (int j = 1; j <= n; j++)
            if (fl == 0)
                break;
            else
                for (int h = 1; h <= n; h++)
                    if (buf[j][h] == 1)
                        fl = 0;
        if (fl) {
            if (res_un > buf_res) {
                res_un = buf_res;
                ind_un = ww;
            }
        }
    }
    cout << count << '\n';
    if (res == inf && res_un == inf) {
        cout << -1;
        return 0;
    }
    if (res <= res_un) {
        cout << res << '\n';
        copy(mm);
        int buf_res = 0;
        change1(rr, ind, buf_res);
        for (int j = 2; j <= n; j++)
            for (int h = 1; h <= n; h++)
                if (buf[j - 1][h] == 1) {

                    cout << j << ' ' << h << '\n';
                    buf[j][h] = !buf[j][h];
                    buf[j - 1][h] = !buf[j - 1][h];
                    buf[j + 1][h] = !buf[j + 1][h];
                    buf[j][h - 1] = !buf[j][h - 1];
                    buf[j][h + 1] = !buf[j][h + 1];
                }
    }
    else {
        cout << res_un << '\n';
        copy(un);
        int buf_res = 0;
        change1(rr, ind_un, buf_res);
        for (int j = 2; j <= n; j++)
            for (int h = 1; h <= n; h++)
                if (buf[j - 1][h] == 1) {
                    cout << j << ' ' << h << '\n';
                    buf[j][h] = !buf[j][h];
                    buf[j - 1][h] = !buf[j - 1][h];
                    buf[j + 1][h] = !buf[j + 1][h];
                    buf[j][h - 1] = !buf[j][h - 1];
                    buf[j][h + 1] = !buf[j][h + 1];
                }
    }
}
//20
//bbbbbbbbbbbbbbbbbbbb
//bbbbbbbbbbbbbbbbbbbb
//bbbbbbbbbbbbbbbbbbbb
//bbbbbbbbbbbbbbbbbbbb
//bbbbbbbbbbbbbbbbbbbb
//bbbbbbbbbbbbbbbbbbbb
//bbbbbbbbbbbbbbbbbbbb
//bbbbbbbbbbbbbbbbbbbb
//bbbbbbbbbbbbbbbbbbbb
//bbbbbbbbbbbbbbbbbbbb
//bbbbbbbbbbbbbbbbbbbb
//bbbbbbbbbbbbbbbbbbbb
//bbbbbbbbbbbbbbbbbbbb
//bbbbbbbbbbbbbbbbbbbb
//bbbbbbbbbbbbbbbbbbbb
//bbbbbbbbbbbbbbbbbbbb
//bbbbbbbbbbbbbbbbbbbb
//bbbbbbbbbbbbbbbbbbbb
//bbbbbbbbbbbbbbbbbbbb
//bbbbbbbbbbbbbbbbbbbb