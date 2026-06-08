#include <bits/stdc++.h>
using namespace std;

int main() {
    int h1, h2, m1, m2;
    cin >> h1 >> m1;
    cin >> h2 >> m2;
    vector<int> v;
    v.push_back(60 + 23);
    v.push_back(60 * 12 + 34);
    v.push_back(60 * 23 + 45);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            //cout << i << " " << j << '\n';
            v.push_back((i * 10 + j) * 60 + j * 10 + i);
        }
    }
    v.pop_back();
    v.pop_back();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == j || i * 10 + j >= 24) {
                continue;
            }
            v.push_back((i * 10 + j) * 60 + i * 10 + j);
        }
    }
    /*for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }*/
    int ans = 0;
    for (int i = h1 * 60 + m1; i <= h2 * 60 + m2; i++) {
        for (int k = 0; k < v.size(); k++) {
            if (v[k] == i) {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
