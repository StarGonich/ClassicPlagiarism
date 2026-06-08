#include <bits/stdc++.h>

using namespace std;
#define int long long
pair<int,int> pp[100000];

 main() {
   
    fill(pp, pp + 100000, make_pair(-1ll, -1ll));
    int n;
    cin >> n;
    if(n == 1){
        cout << 1;
        return 0;
    }
    if(n == 2)
    {
        cout << "3 4 5\n";
        return 0;
    }

    
    int magic = 65536;
    for(int i1 = 1; i1 <= magic/2; i1 ++)
        for(int i2 = i1; i2 <= magic/2; i2 ++)
        {
            int cc = (int)i1 * i1 + i2 * i2 ;    
            int c = (int)sqrt(i1 * i1 + i2 * i2) ;
            if(c * c == cc)
            {
                //if(pp[c] == make_pair(-1ll, -1ll))
                    pp[c] = {i1, i2};
            }    
        }

   
    int ans = 0;

    if(true)
    {
        for(int i1 = 0; i1 <= n; i1 ++)
            for(int i2 = 0; i2 + i1 <= n; i2 ++)
                {
                    int i3 = n - i1 - i2; 
                    int cc = i1  + 4 * i2 + 9 * i3 ;    
                    int c = (int)sqrt(cc) ;
                    if(c * c == cc)
                    {
                       for(int i = 0; i < i1; i ++)
                            cout << 1 << " ";
                        for(int i = 0; i < i2; i ++)
                            cout << 2 << " ";
                        for(int i = 0; i < i3; i ++)
                            cout << 3 << " ";
                        cout << c;
                        return 0;    
                    }    
                }
        cout << -1;
        return 0;
        
        
    }
    while(! ans)
    {
        magic --;
        if(magic == 0)
            break;
        if(pp[magic] == make_pair(-1ll, -1ll))
            continue;
        
        vector<int> res = {magic, pp[magic].second, pp[magic].first};
        while(res.size() != n+1)
        {
            int add = 0;
            for(int i = 1; i < res.size(); i ++)
            {   
                if(res[i] * res[i] - 1 == n + 1 - res.size())
                {
                    res[i] = 1;
                    int ttt = res.size();
                    for(int j = 0; j < n + 1 - ttt; j ++)
                        res.push_back(1);
                    add = 1;
                    assert(res.size() == n+1);
                    break;
                }
            }
            if(add == 0)
            for(int i = 1; i < res.size(); i ++)
            {
                
                if(pp[res[i]] != make_pair(-1ll, -1ll))
                {
                    auto a = pp[res[i]];
                    res[i] = a.first;
                    res.push_back(a.second);
                    add = 1;
                    break;
                }
            }
            // for(auto x : res)
            //     cout << x << " ";
            // cout << endl;
            if(add == 0)
                break;
        }

        if(res.size() != n+1)
            continue;
        else
        {
            reverse(res.begin(), res.end());
            for(auto x : res)
                cout << x << " ";
            return 0;
        }
    }

    cout << -1;


    return 0;
}