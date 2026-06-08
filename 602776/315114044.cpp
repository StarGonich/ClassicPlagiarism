#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> st = {10, 20, 40, 80};
    int s = 210, k = 0;
    
    while (true) {
        cout << st[k] << ' ' << "R\n";
        fflush(stdout);
        
        int x;
        cin >> x;
        
        if (x == 1) {
            s += st[k];
            k = 0;
        }
        if (!x) {
            s -= st[k];
            k++;
        }
        if (x == -1 || s >= 1000) return 0; 
    }
}
