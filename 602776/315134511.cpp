#include <bits/stdc++.h>

using namespace std;
#define int long long

int mod = 1e9 + 9;
int st = 33;

vector<int> perm(int n)
{
    vector<int> res;
    for(int i = 0; i < n; i ++)
        res.push_back(i);
    for(int i = 0; i < 1000; i ++)
    {
        int i1 = rand() % n, i2 = rand()% n;
        swap(res[i1], res[i2]);
    }
    return res;
}

void apppl(string &s, vector<int> p)
{
    string g = s;
    for(int i = 0; i < s.size(); i++)
        g[i] = s[p[i]];
    s = g;
}

void apppl1(string &s, vector<int> p)
{
    vector<int> pp = p;
    for(int i = 0; i < s.size(); i++)
        pp[p[i]] = i;
    string g = s;
    for(int i = 0; i < s.size(); i++)
        g[i] = s[pp[i]];
    s = g;
}


 main() {
   
    int n;
    cin >> n;
    srand(42);
    if(n == 1)
    {
        string s;
        cin >> s;
        
        int hash  = mod - 43;
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
        
        s = s + hh;
        apppl(s, perm(s.size()));
        cout << s;        
    }
    
    else
    {
        string s;
        cin >> s;
        apppl1(s, perm(s.size()));
  
        string hh = s.substr(s.size() - 10, 10);
        s = s.substr(0, s.size() - 10);

        int hash = 0;
        reverse(hh.begin(), hh.end());
        for(int i = 0; i < 10; i ++)
            hash = (hash * 26 + hh[i] - 'A');

        int hashS  = mod - 43;
        for(int i = 0; i < s.size(); i ++)
        {
            hashS = (hashS * st + (s[i] -'A' + 1)) % mod;
        }
        // hash correct 
        int stD = 1;
        for(int i = s.size() - 1; i>=0; i --)
        {
            for(int c = 0; c < 26; c++)
            {
                int nnew = ((hashS - stD * (s[i] - 'A' + 1) % mod)  + mod + stD * (c + 1)) % mod;
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