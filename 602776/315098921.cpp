#include <iostream>

using namespace std;

int main()
{
    int a, b, p;
    int c, d, q;
    cin >> a >> b >> p >> c >> d >> q;
    if(b*c-a*d==0){
        if(p*c-a*q==0){
            cout << "Ambiguity";
        }else{
            cout << "Contradiction";
        }
        return 0;
    }
    long double x = 100.0*(p*d - b*q)/(a*d - b*c);
    long double y = 100.0*(p*c - a*q)/(b*c - a*d);
    if(x < 0 || y < 0 || x == 0 || y == 0){
        cout << "Not positive";
        return 0;
    }
    cout << "Success\n";
    cout << x << ' ' << y;
    return 0;
}
