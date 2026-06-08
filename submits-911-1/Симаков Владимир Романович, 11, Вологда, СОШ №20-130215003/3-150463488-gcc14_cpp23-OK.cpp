#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <functional>

using namespace std;

function<int(int)> make_f(const vector<pair<int,int>>& ads) {
    int n = (int)ads.size();
    vector<int> t1s(n), t2s(n), lens(n), pref(n+1, 0);
    for (int i = 0; i < n; i++) {
        t1s[i] = ads[i].first;
        t2s[i] = ads[i].second;
        lens[i] = t2s[i] - t1s[i];
    }
    for (int i = 0; i < n; i++) {
        pref[i+1] = pref[i] + lens[i];
    }

    return [=](int S) -> int {
        int E = S + 3600;
        int L = (int)(upper_bound(t2s.begin(), t2s.end(), S) - t2s.begin());
        int idx_right = (int)(lower_bound(t1s.begin(), t1s.end(), E) - t1s.begin());
        int R = idx_right - 1;
        if (L > R) return 0;
        if (L == R) {
            return max(0, min(t2s[L], E) - max(t1s[L], S));
        }
        int ol = max(0, min(t2s[L], E) - max(t1s[L], S));
        int orr = max(0, min(t2s[R], E) - max(t1s[R], S));
        int mid = (R - 1 >= L + 1) ? (pref[R] - pref[L+1]) : 0;
        return ol + mid + orr;
    };
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string n_line;
    if (!getline(cin, n_line) || n_line.empty()) {
        return 0;
    }
    int N = stoi(n_line);
    int T;
    cin >> T;
    vector<pair<int,int>> ads(N);
    for (int i = 0; i < N; i++) {
        cin >> ads[i].first >> ads[i].second;
    }
    if (N == 0) {
        cout << -1 << "\n";
        return 0;
    }

    sort(ads.begin(), ads.end());
    auto f = make_f(ads);

    vector<int> t1s(N), t2s(N);
    for (int i = 0; i < N; i++) {
        t1s[i] = ads[i].first;
        t2s[i] = ads[i].second;
    }
    int max_t2 = *max_element(t2s.begin(), t2s.end());
    set<int> events = {0, max_t2 + 1};
    for (auto& ab : ads) {
        int a = ab.first, b = ab.second;
        int candidates[] = {a-3600, a-3600+1, a, a+1, b-3600, b-3600+1, b, b+1};
        for (int x : candidates) {
            if (x >= 0 && x <= max_t2 + 1) {
                events.insert(x);
            }
        }
    }
    vector<int> ev(events.begin(), events.end());

    for (size_t i = 0; i + 1 < ev.size(); i++) {
        int start = ev[i];
        int end = ev[i+1];
        if (start > end - 1) continue;
        int val_start = f(start);
        if (val_start > T) {
            cout << start << "\n";
            return 0;
        }
        int val_end = f(end - 1);
        if (val_end <= T) continue;
        int lo = start, hi = end - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (f(mid) > T) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        cout << lo << "\n";
        return 0;
    }

    cout << -1 << "\n";
    return 0;
}