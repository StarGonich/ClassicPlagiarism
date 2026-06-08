#include <iostream>
#include <numeric> gcd
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int n, s;
    s=6;
    vector <int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    cin >> n;
    if (n==1){
        cout << 1 << endl;
        cout << 1;
    }
    else {
        if (n==2){
            cout << -1;
        }
        else{
            for (int i=3; i<n; i++){
                a.push_back(a[i-1]*2);
                s+=a[i];
            }
            cout << s << endl;
            for (int i=0; i<size(a); i++){
                cout << a[i] << " ";
            }
        }

    }
    return 0;
}