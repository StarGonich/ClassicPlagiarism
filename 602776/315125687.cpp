#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

#define ull unsigned int


struct Mine {
    ull x;
    ull d;

    // bool operator<(const Mine &other) const {
    //     return x < other.x;
    // }

    // bool operator==(const Mine &other) const {
    //     return x == other.x;
    // }
};


int main() {
    int n;
    cin >> n;

    vector<Mine> mines(n);
    {
        vector<ull> x(n);
        for (int i = 0; i < n; i++)
            cin >> x[i];

        vector<ull> d(n);
        for (int i = 0; i < n; i++)
            cin >> d[i];

        for (int i = 0; i < n; i++)
            mines[i] = {x[i], d[i]};
    }

    int k;
    cin >> k;

    queue<Mine> to_visit;
    to_visit.push(mines[k-1]);

    while (!to_visit.empty()) {
        Mine mine = to_visit.front();
        to_visit.pop();

        // cout << mine << ' ' << x[mine] << ' ' << d[mine] << '\n';
        // if (visited.contains(x[mine]))
        //     continue;
        // visited.insert(x[mine]);

        ull mn = mine.x - mine.d;
        ull mx = mine.x + mine.d;

        // cout << mine.x << ' ' << mine.d << '\n';
        // cout << mn << ' ' << mx << '\n';

        auto min = mines.begin();
        if (mine.d <= mine.x)
            min = lower_bound(begin(mines), end(mines), mn,
                [](const Mine &mine, ull val) {
                    return mine.x < val;
                });

        auto max = mines.end();
        if (mx <= mines[n-1].x)
            max = upper_bound(begin(mines), end(mines), mx,
                [](ull val, const Mine &mine) {
                    return val < mine.x;
                });
        
        // cout << (*min).x << ' ' << (*max).x << '\n';
        // cout << distance(begin(mines), min) << ' ' << distance(begin(mines), max) << '\n';

        for (auto it = min; it < max; it++) {
            to_visit.push(*it);
        }

        // cout << '-';
        // for (auto i : mines) {
        //     cout << i.x << ' ';
        // }
        // cout << '\n';

        mines.erase(min, max);
    }

    cout << n - mines.size();

    return 0;
}
