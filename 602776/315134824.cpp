#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int M = 2000000000;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<long long> > gr(n, vector<long long>(n, M));
    vector<long long> c(n);
    for(int i = 0; i < n; ++i){
        cin >> c[i];
        c[i] = min(c[i], c[0]);
        gr[i][i] = 0;
    }
    for(int i = 0; i < m; ++i){
        long long u, v, f;
        cin >> u >> v >> f;
        --u;
        --v;
        gr[u][v] = f;
        gr[v][u] = f;
    }
    vector<long long> d(n, M);
    vector<int> pr_d(n, -1);
    d[n-1] = 0;
    priority_queue<pair<long long, int> > q;
    q.push({M, n-1});
    while(!q.empty()){
        long long l = M - q.top().first;
        int v = q.top().second;
        q.pop();
        //cout << v+1 << endl;
        if(d[v] == l){
            for(int j = 0; j < n; ++j){
                if(d[j] > d[v] + gr[v][j]){
                    d[j] = d[v] + gr[v][j];
                    pr_d[j] = v;
                    q.push({M-d[j], j});
                }
            }
        }
    }
    if(d[0] == M){
        cout << -1;
        return 0;
    }
    vector<long long> l(n, M);
    vector<int> pr_l(n, -1);
    l[0] = 0;
    vector<pair<long long, int> > b;
    for(int i = 1; i < n; ++i){
        b.push_back({M-c[i], i});
    }
    sort(b.begin(), b.end());
    for(int i = 0; i < n-1;){

        int k = b[i].second;
        int cc = c[k];
        priority_queue<pair<long long, int> > qq;
        qq.push({M, 0});
        for(int j = 0; j < i; ++j){
            int o = b[j].second;
            qq.push({M-l[o], o});
        }
        while(!qq.empty()){
            long long ll = M - qq.top().first;
            int v = qq.top().second;
            qq.pop();
            if(l[v] == ll){
                for(int j = 0; j < n; ++j){
                    if(c[j] == cc && l[j] > l[v] + gr[v][j]*c[v]){
                        l[j] = l[v] + gr[v][j]*c[v];
                        pr_l[j] = v;
                        qq.push({M-l[j], j});
                    }
                }
            }
        }
        while(i < n-1 && c[b[i].second] == cc){
            ++i;
        }
    }
    long long ans = M;
    int x = -1;
    for(int i = 0; i < n; ++i){
        if(ans > l[i] + d[i]*c[i]){
            ans = l[i] + d[i]*c[i];
            x = i;
        }
    }
    cout << ans << endl;
    vector<int> g;
    vector<int> z;
    g.push_back(x);
    z.push_back(d[x]);
    int x1 = x;
    while(pr_l[x] != -1){
        int xx = pr_l[x];
        g.push_back(xx);
        z.push_back(gr[xx][x]);
        x = xx;
    }
    for(int i = 0; i < g.size()-1; ++i){
        if(c[g[i]] == c[0]){
            z[g.size()-1] += z[i];
            z[i] = 0;
        }
    }
    vector<int> g1;
    vector<int> z1;
    for(int i = 0; i < g.size(); ++i){
        g1.push_back(g[g.size()-1-i]);
        z1.push_back(z[g.size()-1-i]);
    }
    while(pr_d[x1] != -1){
        x1 = pr_d[x1];
        g1.push_back(x1);
        z1.push_back(0);
    }
    cout << g1.size() << endl;
    for(int i = 0; i < g1.size(); ++i){
        cout << g1[i]+1 << ' ' << z1[i] << endl;
    }
    return 0;
}
