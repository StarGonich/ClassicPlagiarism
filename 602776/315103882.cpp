#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> pos;
    vector<int> len;
    bool bo = false;
    for(int i = 0; i < n; ++i){
        cin >> x[i];
        if(x[i] != i+1){
            if(!bo){
                pos.push_back(i);
                len.push_back(1);
                bo = true;
            }else{
                if(x[pos.back()]+len.back() == x[i]){
                    ++len[len.size()-1];
                }else{
                    pos.push_back(i);
                    len.push_back(1);
                }
            }
        }else{
            if(bo){
                bo = false;
            }
        }
    }
    if(pos.size() != 2){
        cout << -1;
    }else{
        cout << pos[0]+1 << ' ' << len[0] << '\n' << pos[1]+1 << ' ' << len[1];
    }
    return 0;
}
