#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long x,y,z;
    if(!(cin>>x>>y>>z)) return 0;
    const long long INF = 1000000000LL;
    long long sum = 5*z;
    // case all equal
    if(x==y && y==z){
        cout<<x<<" "<<x<<" "<<x<<" "<<x<<" "<<x<<"\n";
        return 0;
    }
    // try pattern: x,x,y,t,u with x <= y
    if(x <= y){
        long long rem = sum - 2*x - y;
        for(long long t = max(y+1, -INF); t <= min(y+100000LL, INF); ++t){
            long long u = rem - t;
            if(u < t) continue;
            if(u < -INF || u > INF) continue;
            if(t==x || u==x) continue;
            if(t==u) continue;
            if(t < y) continue;
            if(u < y) continue;
            cout<<x<<" "<<x<<" "<<y<<" "<<t<<" "<<u<<"\n";
            return 0;
        }
    }
    // try pattern: a,b,y,x,x with x >= y
    if(x >= y){
        long long rem = sum - 2*x - y;
        for(long long b = min(y-1, INF); b >= max(y-100000LL, -INF); --b){
            long long a = rem - b;
            if(a > b) continue;
            if(a < -INF || a > INF) continue;
            if(a==x || b==x) continue;
            if(a==b) continue;
            if(b > y) continue;
            if(a > y) continue;
            cout<<a<<" "<<b<<" "<<y<<" "<<x<<" "<<x<<"\n";
            return 0;
        }
    }
    // x==y possibilities: try three x's
    if(x==y){
        // try 3x + a + b = 5z => a+b = rem
        long long rem = sum - 3*x;
        for(long long a = max(-INF, x-100000LL); a <= min(INF, x+100000LL); ++a){
            long long b = rem - a;
            if(b < -INF || b > INF) continue;
            // ensure sorted: a <= x <= b
            if(!(a <= x && x <= b)) continue;
            // prevent making another value repeated twice equal to x
            // it's fine if a==x or b==x (gives 4 or 5 occurrences) as mode still unique
            if(a==b) continue;
            if(a==x && b==x) { // all equal handled earlier
                continue;
            }
            cout<<a<<" "<<x<<" "<<x<<" "<<x<<" "<<b<<"\n";
            return 0;
        }
        // try 4x + b = 5z
        {
            long long b = sum - 4*x;
            if(b >= -INF && b <= INF){
                if(!(b==x)){ // if b==x then handled earlier as all equal
                    long long a1 = x;
                    long long a2 = x;
                    long long a3 = x;
                    long long a4 = x;
                    long long a5 = b;
                    if(a1<=a2 && a2<=a3 && a3<=a4 && a4<=a5){
                        cout<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<" "<<a5<<"\n";
                        return 0;
                    }
                    vector<long long> v={a1,a2,a3,a4,a5};
                    sort(v.begin(),v.end());
                    cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<" "<<v[3]<<" "<<v[4]<<"\n";
                    return 0;
                }
            }
        }
    }
    // try brute small search for two equal x anywhere by checking integer pairs within small range
    // general brute: try choose two positions for x (counts 2) and choose other three values within limited range
    {
        long long remTotal = sum - 2*x;
        // choose middle must be y, so one of other three must be y and it must be the median after sorting
        // try other two values a,b in range [y-1000,y+1000]
        for(long long a = max(-INF, y-1000LL); a <= min(INF, y+1000LL); ++a){
            if(a==x) continue;
            for(long long b = max(-INF, y-1000LL); b <= min(INF, y+1000LL); ++b){
                if(b==x || b==a) continue;
                long long s = a + b + y;
                if(s != remTotal) continue;
                vector<long long> v = {x,x,y,a,b};
                sort(v.begin(), v.end());
                if(v[2] != y) continue;
                // check unique mode x
                unordered_map<long long,int> cnt;
                for(long long val:v) cnt[val]++;
                int maxc = 0; long long modes = 0;
                for(auto &p:cnt){
                    if(p.second > maxc){ maxc = p.second; modes = p.first; }
                    else if(p.second == maxc) { modes = LLONG_MIN; }
                }
                if(maxc == cnt[x] && modes==x){
                    cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<" "<<v[3]<<" "<<v[4]<<"\n";
                    return 0;
                }
            }
        }
    }
    cout<<-1<<"\n";
    return 0;
}
