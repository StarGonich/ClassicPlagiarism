#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

double eps = 1e-6;

bool eq(double a, double b) {
  return abs(a - b) < eps;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << fixed;
  cout.precision(12);

  int a, b, p;
  cin >> a >> b >> p;

  int c, d, q;
  cin >> c >> d >> q;

  if(c == 0) {
    double y = q / (double)d;
    if(a == 0) {
      if(!eq(y * b, p)) cout << "Contradiction";
      else cout << "Ambiguity";
      return 0;
    }
    double x = (p - b * y) / a;

    if(x < 0 || y < 0) {
      cout << "Not positive";
    } else {
      cout << "Success\n";
      cout << x << ' ' << y << endl;
    }
    return 0;
  }

  if(d == 0) {
    double x = q / (double)c;
    if(b == 0) {
      if(!eq(x * a, p)) cout << "Contradiction";
      else cout << "Ambiguity";
      return 0;
    }
    double y = (p - a * x) / b;

    if(x < 0 || y < 0) {
      cout << "Not positive";
    } else {
      cout << "Success\n";
      cout << x << ' ' << y << endl;
    }
    return 0;
  }

  if(b == 0) {
    double x = q / (double)a;
    if(d == 0) {
      if(!eq(x * c, q)) cout << "Contradiction";
      else cout << "Ambiguity";
      return 0;
    }
    double y = (q - c * x) / d;

    if(x < 0 || y < 0) {
      cout << "Not positive";
    } else {
      cout << "Success\n";
      cout << x << ' ' << y << endl;
    }
    return 0;
  }

  if(a == 0) {
    double y = p / (double)b;
    if(a == 0) {
      if(!eq(y * d, q)) cout << "Contradiction";
      else cout << "Ambiguity";
      return 0;
    }
    double x = (q - d * y) / a;

    if(x < 0 || y < 0) {
      cout << "Not positive";
    } else {
      cout << "Success\n";
      cout << x << ' ' << y << endl;
    }
    return 0;
  }

  if(eq(a / (double)c, b / (double)d) && !eq(a / (double)c, p / (double)q)) {
    cout << "Contradiction\n";
    return 0;
  }

  if(eq(a / (double)c, b / (double)d) && eq(a / (double)c, p / (double)q)) {
    cout << "Ambiguity\n";
    return 0;
  }

  double y = 0;
  if(a == 0) {
    if(b == 0 && p != 0) {
      cout << "Contradiction\n";
      return 0;
    }
    y = p / (double)b;
  } else if(abs(d - b * c / (double)(a)) < eps) {
    if(abs(q - p * c / (double)(a)) < eps) {
      cout << "Ambiguity\n";
      return 0;
    } else {
      cout << "Contradiction\n";
      return 0;
    }
  }

  y = (q - p * c / (double)a);
  y /= d - b * c / (double)a;
  
  double x = 0;
  x = p / (double)a - b / (double)a * y;

  if(x < 0 || y < 0) {
    cout << "Not positive";
  } else {
    cout << "Success\n";
    cout << x * 100 << ' ' << y * 100 << endl;
  }
}