#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> x(n);
    vector<long long> d(n);
    for(int i = 0; i < n; ++i){
        cin >> x[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> d[i];
    }
    int k;
    cin >> k;
    --k;
    int l = k;
    int r = k;
    queue<int> q;
    q.push(k);
    while(!q.empty()){
        int i = q.front();
        q.pop();
        while(l > 0 && x[i] - x[l-1] <= d[i]){
            --l;
            q.push(l);
        }
        while(r < n-1 && x[r+1] - x[i] <= d[i]){
            ++r;
            q.push(r);
        }
    }
    cout << r - l + 1;
    return 0;
}
