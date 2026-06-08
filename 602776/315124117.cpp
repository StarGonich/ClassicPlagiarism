#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n == 1){
        cout << "1 1";
        return 0;
    }
    if(n == 2){
        cout << "3 4 5";
        return 0;
    }
    if(n == 3){
        cout << "3 4 12 13";
        return 0;
    }
    if(n == 4){
        cout << "3 4 12 84 85";
        return 0;
    }
    if(n == 5){
        cout << "3 4 12 84 3612 3613";
        return 0;
    }
    vector<int> ans;
    int k = 0;
    if (n % 3 == 0){
        ans.push_back(3);
        ans.push_back(2);
        ans.push_back(1);
        ans.push_back(1);
        ans.push_back(1);
        ans.push_back(1);
        ans.push_back(1);
        k = 1;
    }
    if(n % 3 == 1){
        ans.push_back(4);
        ans.push_back(2);
        ans.push_back(2);
        ans.push_back(2);
        ans.push_back(1);
        ans.push_back(1);
        ans.push_back(1);
        ans.push_back(1);
        k = 3;
    }
    if(n % 3 == 2){
        ans.push_back(4);
        ans.push_back(3);
        ans.push_back(1);
        ans.push_back(1);
        ans.push_back(1);
        ans.push_back(1);
        ans.push_back(1);
        ans.push_back(1);
        ans.push_back(1);
        k = 0;
    }
    int i = 1;
    int s = ans.size();
    while(ans.size() != n+1){
        if(k == 0){
            for(int j = 0; j < ans.size(); ++j){
                ans[j] <<= 1;
            }
            k += ans.size()-1;
            s = ans.size();
        }else{
            ans[i] >>= 1;
            ans.push_back(ans[i]);
            ans.push_back(ans[i]);
            ans.push_back(ans[i]);
            ++i;
            --k;
            if(i == s){
                i = 1;
            }
        }
    }
    for(int j = 1; j < n+1; ++j){
        cout << ans[j] << ' ';
    }
    cout << ans[0];
    return 0;
}
