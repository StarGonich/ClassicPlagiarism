#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int main()
{
    int h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;
    int minst = h1*60+m1;
    int minfn = h2*60+m2;
    int ans = 0;

    vector<int> num;

    for(int i= minst; i<= minfn; i++){
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
        int one = hstr/10;
        int two = hstr%10;
        int free = mstr/10;
        int four = mstr%10;
        num.push_back(one);
        num.push_back(two);
        num.push_back(free);
        num.push_back(four);
        ans++;
        for(int j=1; j<5; j++){
            if(num[i-1] != num[i]+1){
                ans--;
                i = 10;
            }
        }
    }

    cout << ans;
    return 0;
}
