#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int main()
{
    int h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;
    int ans = 0;

    vector<int> num;

    for(int i= h1*60+m1; i<= h2*60+m2; i++){
        int hstr = i/60;
        int mstr = i%60;
        if(hstr == mstr){
            ans++;
            continue;
        }
        if((hstr/10 == mstr%10) && (hstr%10 == mstr/10)){
            ans++;
            continue;
        }
        if((hstr/10+1 == hstr%10) && (hstr%10 + 1 == mstr/10) && (mstr/10+1 == mstr%10)){
            ans++;
            continue;
        }
    }
    cout << ans;
    return 0;
}
