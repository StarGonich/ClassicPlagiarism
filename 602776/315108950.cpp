#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define PI 3.1415926535897932

#define int long long
const int MOD = 1e9 + 7;

template<typename T = int>
struct Point {
    T x, y;
    Point(T x = 0, T y = 0): x(x), y(y) {}
    Point operator+(const Point& other) const {
        return {x + other.x, y + other.y};
    }
    Point operator-(const Point& other) const {
        return {x - other.x, y - other.y};
    }
    T operator*(const Point& other) const {
        return x * other.x + y * other.y;
    }
    T operator/(const Point& other) const {
        return x * other.y - y * other.x;
    }
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
    T size2() const {
        return x * x + y * y;
    }
    double size() const {
        return sqrt(size2());
    }
    double polar() const { // [-pi, pi]
        return atan2(y, x);
    }
    double polar2() const {
        double res = polar();
        if (res < 0) {
            res += 2 * PI;
        }
        return res;
    }
    Point<double> rotated(double angle) const {
        return {x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle)};
    }
    double angle_to(const Point<T>& other) { // oriented [0, 2*pi]
        return Point<double>(*this * other, *this / other).polar2();
    }
    friend istream& operator>>(istream& in, Point& P) {
        in >> P.x >> P.y;
        return in;
    }
    friend ostream& operator<<(ostream& out, const Point& P) {
        out << P.x << " " << P.y;
        return out;
    }
};

template<typename T = int>
struct Line {
    T a, b, c;
    Line(Point<T> A = {}, Point<T> B = {}) {
        a = B.y - A.y;
        b = A.x - B.x;
        c = -a * A.x - b * A.y;
    }
    Point<T> normal() {
        return {a, b};
    }
    Point<T> dir() {
        return {-b, a};
    }
    void intersect_with(const Line& other) {
        T denom = b * other.a - a * other.b;
        T num_x = c * other.b - b * other.c;
        T num_y = a * other.c - c * other.a;
        if (denom == 0) { // be careful with EPS
            if (num_x == 0) { // be careful with EPS
                cout << "Ambiguity\n";
                return;
            } else {
                cout << "Contradiction\n";
                return;
            }
        }
        double x = (double)num_x / denom, y = (double)num_y / denom;
        if (x <= 0 || y < 0) {
            cout << "Not positive\n";
            return;
        }
        cout << "Success\n";
        cout << x * 100 << " " << y * 100 << "\n";
    }
    template<typename T2>
    double dist_to(const Point<T2>& P) {
        return (double)abs(a * P.x + b * P.y + c) / normal().size();
    }
    template<typename T2>
    Point<double> closest_to(const Point<T2>& P) {
        return {(double)(b * (b * P.x - a * P.y) - a * c) / normal().size2(),
                (double)(a * (-b * P.x + a * P.y) - b * c) / normal().size2()};
    }
    friend istream& operator>>(istream& in, Line& L) {
        in >> L.a >> L.b >> L.c;
        return in;
    }
    friend ostream& operator<<(ostream& out, const Line& L) {
        out << L.a << " " << L.b << " " << L.c;
        return out;
    }
};

void solve() {
    cout << fixed << setprecision(15);

    /*
    int a, b, p; cin >> a >> b >> p;
    int c, d, q; cin >> c >> d >> q;

    if (a * d == b * c) {
        if (a * q == p * c) {
            cout << "Ambiguity\n"; // ?
        } else {
            cout << "Contradiction\n";
        }
        return;
    }


    if (a == 0) {
        double y = (double)p / b;
        double x = (double)(q - d * y) / c;
        if (x <= 0 || y <= 0) {
            cout << "Not positive\n";
        } else {
            cout << x << " " << y << "\n";
        }
        return;
    }*/

    Line<int> A, B; cin >> A >> B;
    A.c *= -1; B.c *= -1;
    A.intersect_with(B);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int Q = 1;
    // cin >> Q;
    while (Q--) {
        solve();
    }
}
