#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> matrix;

const int p = 1000000007;
matrix mul(matrix a, matrix b) {
    matrix c(3, vector<int>(3, 0));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j];
        }
    }
    return c;
}

matrix pow(matrix m, int p) {
    if (p == 1) return m;
    if (p % 2 == 1) return mul(m, pow(m, p-1));
    matrix c = mul(m, m);
    return pow(c, p/2);
}

long long f(int x) {
    if (x == -1) return 1;
    if (x == 0) return 1;
    if (x == 1) return 2;
    matrix m(3, vector<int>(3, 0));
    m[1][0] = 1;
    m[1][2] = 1;
    m[2][1] = 1;
    m[2][2] = 1;
    return pow(m, x+1)[2][2];
}

int main() {
    int n;
    cin >> n;
    long long s = 0;
    for (int i = 0; i < n-1; ++i){
        //cout << f(i-1) << " " << f(n - 3 - i) << "\n";
        s = (s + f(i-1) * f(n - 3 - i)) % p;
    }
    cout << s;
}

