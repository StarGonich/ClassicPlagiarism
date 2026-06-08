#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    short h1, m1, h2, m2, cnt = 0;
    cin >> h1 >> m1 >> h2 >> m2;
    short t1 = h1 * 60 + m1, t2 = h2 * 60 + m2;
    for(short t = t1; t != t2; t++){
        if(t >= 1440){
            t -= 1440;
        }
        int h = t / 60, m = t % 60;
        if((h == m)
        || ((h / 10 == m % 10) && (h % 10 == m / 10))
        || ((h / 10 + 1 == h % 10) && (h % 10 + 1 == m / 10) && (m / 10 + 1 == m % 10))){
            cnt++;
            //cout << h << ' ' << m << '\n';
        }
    }
    cout << cnt;
    return 0;
}
