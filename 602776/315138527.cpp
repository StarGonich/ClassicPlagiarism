#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const int N = 21;
const int NN = 400 + 1;

using Row = bitset<NN>;

string arr[N];

int dx[] = {-1, 0, 1, 0, 0};
int dy[] = {0, -1, 0, 1, 0};

int n;
int is_safe(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

int to_idx(int x, int y) {
    return n * x + y;
}

void solve(vector<Row>& vec) {
    int n = vec.size();

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (vec[j][i]) {
                swap(vec[i], vec[j]);
                break;
            }
        }
        for (int j = 0; j < n; j++) {
            if (i != j && vec[j][i]) {
                vec[j] ^= vec[i];
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<pair<int, int>> ans1;
    {
        vector<Row> eq(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int lol = to_idx(i, j);
                for (int k = 0; k < 5; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    int kek = to_idx(x, y);
                    if (is_safe(x, y)) {
                        eq[lol][kek] = 1;
                    }
                }
                eq[lol][n * n] = arr[i][j] != 'b';
            }
        }
        solve(eq);
        for (int i = 0; i < n * n; i++) {
            if (eq[i][n * n]) {
                ans1.emplace_back(i / n, i % n);
            }
        }
    }

    vector<pair<int, int>> ans2;
    {
        vector<Row> eq(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int lol = to_idx(i, j);
                for (int k = 0; k < 5; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    int kek = to_idx(x, y);
                    if (is_safe(x, y)) {
                        eq[lol][kek] = 1;
                    }
                }
                eq[lol][n * n] = arr[i][j] == 'b';
            }
        }
        solve(eq);
        for (int i = 0; i < n * n; i++) {
            if (eq[i][n * n]) {
                ans2.emplace_back(i / n, i % n);
            }
        }
    }

    auto ans = (ans1.size() < ans2.size() ? ans1 : ans2);

    for (auto [x, y] : ans) {
        for (int i = 0; i < 5; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (is_safe(nx, ny)) {
                arr[nx][ny] = (arr[nx][ny] == 'b' ? 'w' : 'b');
            }
        }
    }

    bool flg = true;
    char c = arr[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] != c) {
                flg = false;
                break;
            }
        }
    }
    if  (!flg) { cout << "-1\n"; return 0;}

    cout << ans.size() << "\n";
    for (auto [x, y] : ans) {
        cout << x + 1 << " " << y + 1 << "\n";
    }
}