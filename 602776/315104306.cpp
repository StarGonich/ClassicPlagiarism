#include <bits/stdc++.h>

using namespace std;

int x[100005];
int d[100005];

int main() {
    int n;
    
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> x[i];
    }
    for(int i = 0; i < n; i ++)
    {
        cin >> d[i];
    }

    int k;
    cin >> k;
    k--;

    int ll = x[k] - d[k];
    int rr = x[k] + d[k];
    int li = k;
    int ri = k;
    int ans = 1;
    while(li >= 0 && ri < n)
    {
        int add = 0;
        while(li > 0 && x[li - 1] >= ll)
        {
            li--;
            ll = min(ll, x[li] - d[li]);
            rr = max(rr, x[li] + d[li]);
            add ++;
        }
        while(ri < n-1 && x[ri + 1] <= rr)
        {
            ri++;
            rr = max(rr, x[ri] + d[ri]);
            ll = min(ll, x[ri] - d[ri]);
            add ++;
        }
        ans += add;
        if(add == 0)
            break;
    }
    cout << ans;

    return 0;
}