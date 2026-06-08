#include <bits/stdc++.h>

using namespace std;

int p[200005];
set<int> bad;

int main() {
   
    int n;
    cin >> n;
    for(int i = 1; i<=n; i ++){
        cin >> p[i];
        if(p[i] != i)
            bad.insert(i);
    }

    int l1 = 0,  l2 = 1, r2 = 2, r1 = 1;
    for(int i = 1; i <= n; i ++)
    {
        if(p[i] != i)
        {   
            l1 = i;
            break; 
        }
    }

    for(int i = n; i >= 1; i --)
    {
        if(p[i] != i)
        {   
            r2 = i;
            break; 
        }
    }
    for(int i  = 1; i <= n; i ++)
        if(p[i] == l1)
        {
            l2 = i;
            break;
        }
    for(int i = 1; i <= n; i ++)
        if(p[i] == r2)
        {
            r1 = i;
            break;
        }
    

    if(!(l1 <= r1 && l2 <= r2 && (r2 < l1 || r1 < l2)))
        cout << -1;
    else
        {
            vector<int> res;
            res.push_back(0);
            for(int i = 1; i < l1; i ++)
                res.push_back(p[i]);
            for(int i = l2; i <= r2; i ++)
                res.push_back(p[i]);
            for(int i = r1 + 1; i < l2; i ++)
                res.push_back(p[i]);
            for(int i = l1; i <= r1; i ++)
                res.push_back(p[i]);
            for(int i = r2 + 1; i <= n; i ++)
                res.push_back(p[i]);

            int sorted = 1;
            for(int i = 0; i <= n; i ++){

                if(res[i] != i)
                    sorted = 0;
            }
            
            if(sorted)
            {
                cout << l1 << " " << r1 - l1 + 1 << " " << l2 << " " << r2 - l2 + 1 << endl;
            }
            else   
                cout << -1;       
        }
    return 0;
}