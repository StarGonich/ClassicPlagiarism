#include <iostream>
#include <queue>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> x(n), d(n);
    for (int& i : x) {
        cin >> i;
    }
    for (int& i : d) {
        cin >> i;
    }
    int k;
    cin >> k;

    set<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        st.emplace(x[i], i);
    }

    queue<int> q;
    q.push(k);

    while (q.size()) {
        int i = q.front();
        q.pop();

        st.erase({x[i], i});

        int lb = x[i] - d[i];
        int rb = x[i] + d[i];

        while (true) {
            auto it = st.lower_bound({lb, 0});
            if (it == st.end() || it->first > rb) break;
            q.push(it->second);
            st.erase(it);
        }
    }

    cout << n - st.size() << "\n";
}