#include <bits/stdc++.h>

using namespace std;
vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
vector<int> dy = {-1, 0, 1, -1, 1, -1, 1, 0};

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int k;
    cin >> k;
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>> v(k, vector<vector<int>> (n + 2, vector<int> (m + 2, 1e9)));
    for(int t = 0; t < k; t++){
		for(int i = 1; i < n + 1; i++){
			for(int j = 1; j < m + 1; j++){
				cin >> v[t][i][j];
			}
		}
    }
    vector<int> ans(k, -1);
    for(int t = 0; t < k; t++){
		vector<vector<int>> d(n + 2, vector<int> (m + 2, 1e9));
		for(int i = 1; i < n + 1; i++){
			for(int j = 1; j < m + 1; j++){
				int k0 = 0;
				for(int h = 0; h < 8; h++){
					if(v[t][i + dx[h]][j + dy[h]] == 1) k0++;
				}
				d[i][j] = v[t][i][j];
				if(d[i][j] == 0 && k0 == 3) d[i][j] = 1;
				else if((d[i][j] == 1 && (k0 != 3 && k0 != 2))) d[i][j] = 0;
			}
		}
		for(int h = 0; h < k; h++){
			if(h == t) continue;
			bool f = 1;
			for(int i = 1; i < n + 1; i++){
				for(int j = 1; j < m + 1; j++){
					if(d[i][j] != v[h][i][j]) f = 0;
				}
			}
			if(f){
				ans[t] = h;
				break;
			}
		}
    }
    vector<bool> s(k, 0);
    for(int i = 0; i < k; i++){
		if(ans[i] != -1){
			s[ans[i]] = 1;
		}
    }
    int p = -1;
    for(int i = 0; i < k; i++){
		if(!s[i]) p = i;
    }
    while(k--){
		cout << p + 1 << " ";
		p = ans[p];
    }
    return 0;
}
