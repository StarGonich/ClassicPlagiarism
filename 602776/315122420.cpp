#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <queue>
#include <vector>
#include <string>
#include <stdio.h>
#include <bitset>

using namespace std;
#define ll long long
#define ld long double
ll Fast_pow(ll st, ll ch, ll mod) {
    ll ost = 1;
    while (st > 1) {
        if (st % 2 == 1) {
            st--;
            ost *= ch;
            ost %= mod;
        }
        st /= 2;
        ch *= ch;
        ch %= mod;
    }
    return (ch * ost) % mod;
}
ll NOD(ll a, ll b) {
    if (b == 0) return a;
    else return NOD(b, a % b);
}
ll NOK(ll a, ll b, ll nod) {
    return a * b / nod;
}
vector<ll> min_Tree(1e7), max_Tree(1e7);
void update_min(int nom, ll ch) {
    min_Tree[nom] = ch;
    while (nom > 0) {
        nom /= 2;
        min_Tree[nom] = min(min_Tree[nom * 2], min_Tree[nom * 2 + 1]);
    }
}
void update_max(int nom, ll ch) {
    max_Tree[nom] = ch;
    while (nom > 0) {
        nom /= 2;
        max_Tree[nom] = max(max_Tree[nom * 2], max_Tree[nom * 2 + 1]);
    }
}
ll Min_Tree(ll nom, int lt, int rt, int l, int r) {
    if (l <= lt && rt <= r) {
        return min_Tree[nom];
    }
    if (lt < l || rt < r) {
        return 10000000;
    }
    int mid = (rt + lt) / 2;
    return min(Min_Tree(nom * 2, lt, mid, l, r), Min_Tree(nom * 2+1, lt, mid, l, r));
}
ll Max_Tree(ll nom, int lt, int rt, int l, int r) {
    if (l <= lt && rt <= r) {
        return max_Tree[nom];
    }
    if (lt < l || rt < r) {
        return -1;
    }
    int mid = (rt + lt) / 2;
    return max(Max_Tree(nom * 2, lt, mid, l, r), Max_Tree(nom * 2 + 1, lt, mid, l, r));
}
pair<ld,ld> ur1(ld A, ld B, ld C, ld D, ld p, ld q) {
    pair<ld, ld> otv;
    if (A == 0) return { 10000000,10000000 };
    ld dl, chl;
    dl = D - B * C / A;
    chl = q - C * p / A;
    if (dl == 0) return { 10000000,10000000 };
    ld l, k;
    l = chl / dl;
    k = (p - B * l) / A;
    return { k,l };
}
pair<ld, ld> ur2(ld A, ld B, ld C, ld D, ld p, ld q) {
    pair<ld, ld> otv;
    if (B == 0) return { 10000000,10000000 };
    ld dk, chk;
    dk = C - D * A / B;
    chk = q - D * p / B;
    if (dk == 0) return { 10000000,10000000 };
    ld l, k;
    k = chk / dk;
    l = (p - A * k) / B;
    return { k,l };
}
pair<ld, ld> ur3(ld A, ld B, ld C, ld D, ld p, ld q) {
    pair<ld, ld> otv;
    if (C == 0) return { 10000000,10000000 };
    ld dl, chl;
    dl = B - A * D / C;
    chl = p - A * q / C;
    if (dl == 0) return { 10000000,10000000 };
    ld l, k;
    l = chl / dl;
    k = (q - D * l) / C;
    return { k,l };
}
pair<ld, ld> ur4(ld A, ld B, ld C, ld D, ld p, ld q) {
    pair<ld, ld> otv;
    if (D == 0) return { 10000000,10000000 };
    ld dk, chk;
    dk = A - C * B / D;
    chk = p - B * q / D;
    if (dk == 0) return { 10000000,10000000 };
    ld l, k;
    k = chk / dk;
    l = (q - C * k) / D;
    return { k,l };
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //ld A, B, p, C, D, q;
    //cin >> A >> B >> p;
    //cin >> C >> D >> q;
    //A /= 100;
    //B /= 100;
    //C /= 100;
    //D /= 100;
    //pair<ld, ld> u1, u2, u3, u4, bd;
    //bd = { (ld)10000000,(ld)10000000 };
    //u1 = ur1(A, B, C, D, p, q);
    //u2 = ur2(A, B, C, D, p, q);
    //u3 = ur3(A, B, C, D, p, q);
    //u4 = ur4(A, B, C, D, p, q);
    //if (A == C && B == D && p == q) {
    //    //cout << A << ' ' << B << ' ' << C << ' ' << D << ' ' << p<<' ' << q;
    //    cout << "Ambiguity";
    //    return 0;
    //}
    //if (A / C == B / D && p == q) {
    //    cout << "Contradiction";
    //    return 0;
    //}/*
    //if (u1 == bd && u2 == bd && u3 == bd && u4 == bd) {
    //    cout << "Contradiction";
    //}*/
    //if (u1 != bd) {
    //    if (u2 == bd) u2 = u1;
    //    if (u3 == bd) u3 = u1;
    //    if (u4 == bd) u4 = u1;
    //}
    //else if (u2 != bd) {
    //    if (u1 == bd) u1 = u2;
    //    if (u3 == bd) u3 = u2;
    //    if (u4 == bd) u4 = u2;
    //}
    //else if (u3 != bd) {
    //    if (u1 == bd) u1 = u3;
    //    if (u2 == bd) u3 = u3;
    //    if (u4 == bd) u4 = u3;
    //}
    //else if (u4 != bd) {
    //    if (u1 == bd) u1 = u4;
    //    if (u2 == bd) u3 = u4;
    //    if (u3 == bd) u4 = u4;
    //}
    //cout << fixed << setprecision(20)<<u1.first << ' ' << u1.second << '\n';
    //cout << fixed << setprecision(20) << u2.first << ' ' << u2.second << '\n';
    //cout << fixed << setprecision(20) << u3.first << ' ' << u3.second << '\n';
    //cout << fixed << setprecision(20) << u4.first << ' ' << u4.second << '\n';
    //cout << (u1 == u2) << (u2 == u3) << (u3 == u4);
    //if (u1 != u2 || u2 != u3 || u3 != u4) {
    //    cout << "Ambiguity";
    //    return 0;
    //}
    //if (u1.first<0 || u1.second<0) {
    //    cout << "Not positive";
    //    return 0;
    //}
    //cout << "Success\n";
    //cout << fixed << setprecision(3) << u1.first << ' ' << u1.second;
    int n; cin >> n;
    vector<int> Ch(n);
    vector<pair<int, pair<int, int>>> T,Tstar;
    for (int i = 0; i < n; i++) cin >> Ch[i];
    T.push_back({ Ch[0],{1,1} });
    Tstar.push_back({ Ch[0],{1,1} });
    for (int i = 1; i < n; i++) {
        if (Ch[i] - Ch[i - 1] == 1) {
            T[T.size()-1].second.second++;
            Tstar[T.size() - 1].second.second++;
        }
        else {
            T.push_back({ Ch[i],{ i + 1, 1 } });
            Tstar.push_back({ Ch[i],{ i + 1, 1 } });
        }
    }
    if (T.size() > 4 || T.size()==1) {
        cout << -1;
        return 0;
    }
    //cout << 1;
    if (T.size() == 2) {
        cout << T[0].second.first<< ' ' << T[0].second.second << '\n';
        cout << T[1].second.first << ' ' << T[1].second.second << '\n';
        return 0;
    }
    sort(T.begin(), T.end());
    int nach1=0, dl1=0, nach2=0, dl2=0;
    for (int i = 0; i < T.size(); i++) {
        if (T[i] != Tstar[i] && dl2==0) {
            if (dl1 == 0) {
                dl1 = T[i].second.second;
                nach1 = T[i].second.first;
            }
            else {
                dl2 = T[i].second.second;
                nach2 = T[i].second.first;
            }
        }
        else if (T[i] != Tstar[i] && dl2 != 0) {
            cout << -1; return 0;
        }
    }
    if (nach1 > nach2) {
        swap(nach1, nach2);
        swap(dl1, dl2);
    }
    cout << nach1 << ' ' << dl1 << '\n';
    cout << nach2 << ' ' << dl2 << '\n';
}