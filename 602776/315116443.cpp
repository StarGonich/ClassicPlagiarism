#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int lose = 0;
    int m = 210;
    vector<int> x(4);
    vector<int> v(4);
    x[0] = 8;
    x[1] = 24;
    x[2] = 56;
    x[3] = 120;
    v[0] = 8;
    v[1] = 16;
    v[2] = 24;
    v[3] = 32;
    while(m < 1000){
        cout << x[lose] << " R" << endl;
        int res;
        cin >> res;
        if(res == -1){
            return 0;
        }else if (res == 0){
            ++lose;
        }else{
            m += v[lose];
            lose = 0;
        }
    }
    return 0;
}
