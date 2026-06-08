#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct event {
    int x, type, pre;
    event(int xx, int typee, int pree) {
        x = xx;
        type = typee;
        pre = pree;
    }
    event() = default;
};

bool operator<(event a, event b) {
    if (a.x == b.x) return a.type > b.type;
    return a.x < b.x;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);

    int n, t;
    cin >> n >> t;
    vector<event> events;

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        events.push_back({l, 1, -1});
        events.push_back({r, -1, l});
    }
    sort(events.begin(), events.end());

    vector<ll> pref(events.size(), 0);

    for (int i = 1; i < events.size(); i++) {
        pref[i] = pref[i - 1];
        if (events[i].type == -1) pref[i] += events[i].x - events[i].pre;
        //cout << pref[i] << " ";
    }

    int j = 0;

    for (auto e : events) {
        //cout << e.x << " ";
        int l = 0, r = events.size();
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (events[mid].x > e.x + 3600) r = mid;
            else l = mid;
        }
        if (pref[l] - pref[j] > t) {
            cout << e.x;
            return 0;
        }
        //cout << l << '\n';
        j++;
    }

    cout << "-1";

    return 0;
}
