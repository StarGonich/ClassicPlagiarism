
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int T;
    cin >> T;
    vector<int> t;

    for(int i=0; i<N; i++){
        int t1, t2;
        cin >> t1 >> t2;
        t.push_back(t1);
        t.push_back(t2);
    }

    vector<bool> time (t[2*N-1]+1,0);

    for(int i=0; i<2*N-1; i+=2){
        for(int j=t[i]; j<=t[i+1]; j++){
            time[j] = 1;
        }
    }

    int l = t[0];
    int r = t[0]+3599;

    int sum = 0;

    if(t[0]+3599 > time.size()){
        r = time.size();
        for(int i=0; i<r; ++i){
            if(time[i]){
                sum++;
            }
        }
        if(sum>T){
            cout << 0;
        }
        else{
            cout << -1;
        }
        return 0;

    }

    for(int i=l; i<=r; i++){
        if(time[i]){
            sum++;
        }
    }
    //cout << sum;

    while(r<time.size()){
        if(sum>T){
            cout << l+1;
            //cout << sum;
            return 0;
        }
        if(time[r+1]){
            sum++;
        }
        if(time[l]){
            sum--;
        }
        l++;
        r++;

    }

    cout << -1;



    return 0;
}
