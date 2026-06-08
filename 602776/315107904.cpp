#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> x(n);
    int pos1, len1, pos2, len2;
    pos1 = -1;
    pos2 = -1;
    int k = 1;
    bool bo1 = true;
    bool bo2 = true;
    for(int i = 0; i < n; ++i){
        cin >> x[i];
        if(pos1 == -1){
            if(x[i] == k){
                ++k;
            }else{
                pos1 = i;
                len1 = 1;
            }
        }else{
            if(x[i] == k){
                pos2 = i;
                len2 = 1;
            }else{
                if(pos2 == -1){
                    if(bo1 && x[pos1] + len1 == x[i]){
                        ++len1;
                    }else{
                        bo1 = false;
                    }
                }else{
                    if(bo2 && x[pos2] + len2 == x[i]){
                        ++len2;
                    }else{
                        bo2 = false;
                    }
                }
            }
        }
    }
    if(pos1 == -1){
        cout << -1;
        return 0;
    }
    vector<int> ans(n);
    int ij = 0;
    for(int i = 0; i < pos1; ++i){
        ans[ij] = x[i];
        ++ij;
    }
    for (int i = pos2; i < pos2+len2; ++i){
        ans[ij] = x[i];
        ++ij;
    }
    for(int i = pos1+len1; i < pos2; ++i){
        ans[ij] = x[i];
        ++ij;
    }
    for (int i = pos1; i < pos1+len1; ++i){
        ans[ij] = x[i];
        ++ij;
    }
    for (int i = pos2+len2; i < n; ++i){
        ans[ij] = x[i];
        ++ij;
    }
    for(int i = 0; i < n; ++i){
        if(ans[i] != i+1){
            cout << -1;
            return 0;
        }
    }
    cout << pos1 + 1 << ' ' << len1 << '\n' << pos2 + 1 << ' ' << len2;
    return 0;
}
