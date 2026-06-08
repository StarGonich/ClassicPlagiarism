using namespace std;
int main() {
    int n;
    cin >> n;
    int cnt;
    for (int i = 4; i <= n; i++) {
            if (i % 4 == 0 && i % 5 != 0 && i % 6 != 0 ||
                    i % 4 != 0 && i % 5 == 0 && i % 6 != 0 ||
                    i % 4 != 0 && i % 5 != 0 && i % 6 == 0) {
                cnt++;
            }
        }
    cout << cnt;
}