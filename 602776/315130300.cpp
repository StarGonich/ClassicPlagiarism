#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

vector<bool> used(100000, 0);
set<long long> explode(vector<long long> &x, vector<long long> &d, long long i){
    set<long long> st;
    set<long long> stTemp;
    long long coorTemp = x[i];
    long long distTemp = d[i];
    for(long long i = 0; i < x.size(); i++){
        if(abs(coorTemp - x[i]) <= distTemp){
            if(used[i] == 0){
                used[i] = 1;
                stTemp = explode(x, d, i);
                st.insert(stTemp.begin(), stTemp.end());

            }
            st.insert(i);
            //cout << i << ' ';
        }
    }
    //cout << endl;
    return st;
}


int main()
{

    long long n;
    cin >> n;
    vector<long long> x(n);
    vector<long long> d(n);

    for(long long i = 0; i < n; i++){
        cin >> x[i];
    }
    for(long long i = 0; i < n; i++){
        cin >> d[i];
    }


    long long k;
    cin >> k;
    long long coor;
    long long dist;
    used[k - 1] = 1;
    coor = x[k - 1];
    dist = d[k - 1];

    set<long long> stt;
    set<long long> sttTemp;
    stt.insert(x[k - 1]);

    for(long long i = 0; i < n - 1; i++){
        if(abs(coor - x[i]) <= dist){
            cout << i << ":" << endl;
            if(used[i] == 0){
                used[i] = 1;
                sttTemp = explode(x, d, i);
                stt.insert(sttTemp.begin(), sttTemp.end());

            }


        }
    }
    //cout << stt.size();
}
