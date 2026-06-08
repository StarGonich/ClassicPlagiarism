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
    for (int i = 0; i < n; ++i)
        delts.insert(i + 1 - a[i]);
    delts.erase(0);

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
        if (pos.find(i + 1 - a[i]) == pos.end()) {
            pos[i + 1 - a[i]] = i + 1;
        }
    }

    for (auto delta : delts)
        cout << pos[delta] << ' ' << len[delta] << '\n';

    return 0;
}

