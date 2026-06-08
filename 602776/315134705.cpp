#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    if (is_sorted(a, a + n)) {
        cout << "-1\n";
        return 0;
    }

    set <int> delts;
    for (int i = 0; i < n; ++i) {
        //cout << i + 1 - a[i] << ' ';
        delts.insert(i + 1 - a[i]);
    }
    /*cout << '\n';
    for (auto d : delts)
        cout << d << ' ';
    cout << '\n';*/
    delts.erase(0);
    /*for (auto d : delts)
        cout << d << ' ';
    cout << '\n';*/
    
    if (delts.size() == 3) {
        auto x = *delts.begin();
        auto y = *delts.rbegin();
        unordered_map <int, int> pos;
        unordered_map <int, int> len;
        for (int i = 0; i < n; ++i) {
            if (i + 1 - a[i] == 0)
                continue;
            if (i + 1 - a[i] == x)
                ++len[x];
            if (i + 1 - a[i] == y)
                ++len[y];
            if (pos.find(i + 1 - a[i]) == pos.end())
                pos[i + 1 - a[i]] = i + 1;
        }

        //cout << "hello\n" << len[x] << ' ' << len[y] << ' ' << *(++delts.begin()) << '\n';
        if (len[x] - len[y] - *(++delts.begin()) != 0) {
            cout << "-1\n";
            return 0;
        }
        
        cout << pos[x] << ' ' << len[x] << '\n';
        cout << pos[y] << ' ' << len[y] << '\n';
        
        return 0;    
    }

    if (delts.size() != 2) {
        cout << "-1\n";
        return 0;
    }

    unordered_map <int, int> pos;
    unordered_map <int, int> len;
    for (int i = 0; i < n; ++i) {
        if (i + 1 - a[i] == 0)
            continue;
        if (delts.count(i + 1 - a[i]))
            ++len[i + 1 - a[i]];
        if (pos.find(i + 1 - a[i]) == pos.end())
            pos[i + 1 - a[i]] = i + 1;
    }

    vector <pair <int, int>> ans;
    for (auto delta : delts)
        ans.emplace_back(pos[delta], len[delta]);
    sort(ans.begin(), ans.end());
    for (const auto [pos, len] : ans)
        cout << pos << ' ' << len << '\n';

    return 0;
}
/*
8
1 4 2 5 3 6 7 8
*/
