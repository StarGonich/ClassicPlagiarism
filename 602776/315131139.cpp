#include <bits/stdc++.h>

using namespace std;
#define int long long

int mod = 1e9 + 7;
int st = 31;

 main() {
   
    int n;
    cin >> n;

    if(n == 1)
    {
        string s;
        cin >> s;
        swap(s[0], s[1]);
        cout << s;
        swap(s[0], s[1]);
        
        int hash  = 0;
        for(int i = 0; i < s.size(); i ++)
        {
            hash = (hash * st + (s[i] -'A' + 1)) % mod;
        }
        string hh = "";
        while(hash != 0)
        {
            hh += hash % 26 + 'A';
            hash /= 26;
        }
        while(hh.size() != 10)
            hh += 'A';
        cout << hh;
        
    }
    
    else
    {
        string s;
        cin >> s;
        swap(s[0], s[1]);
        string hh = s.substr(s.size() - 10, 10);
        s = s.substr(0, s.size() - 10);

        int hash = 0;
        reverse(hh.begin(), hh.end());
        for(int i = 0; i < 10; i ++)
            hash = (hash * 26 + hh[i] - 'A');

        int hashS  = 0;
        for(int i = 0; i < s.size(); i ++)
        {
            hashS = (hashS * st + (s[i] -'A' + 1)) % mod;
        }
        // hash correct 
        int stD = 1;
        for(int i = n; i>=0; i --)
        {
            for(int c = 0; c < 26; c++)
            {
                int nnew = ((hashS - stD * (s[i] - 'A' + 1))  + mod + stD * (c + 1)) % mod;
                if(nnew == hash)
                {
                    s[i] = 'A' + c;
                    cout << s;
                    return 0;
                }
            }
            stD = stD * st % mod;
        }
        cout << s;
    }

    return 0;
}