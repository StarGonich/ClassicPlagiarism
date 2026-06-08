#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int T;
    int n;
    cin >> n;
    cin >> T;
    vector <pair<int, int>> Otr;
    for (int i=0; i<n; ++i){
        pair <int, int> rt;
        cin >> rt.first >> rt.second;
        Otr.push_back(rt);
    }
    if (n==1){
        if(Otr[0].first+Otr[0].second>T){
            if(Otr[0].second-3600-(Otr[0].second-Otr[0].first-T+1)<=0){
                cout << 0;
            }
            else{
                cout << Otr[0].second-3600-(Otr[0].second-Otr[0].first-T+1);
            }

        }
        else
            cout << -1;
        return 0;
    }
    vector <int> dagtr;
    for (int i=0; i<n-1; ++i){
        if(T==3599&&Otr[i].second-Otr[i].first[i]>=3600){
			cout << Otr[i].first;
			return 0;
        }
        if (T<3599&&Otr[i].second-Otr[i].first>3600){
			if (Otr[i].first-3600+T<0){
				cout << 0;
				return 0;
			}
			else{
				cout << Otr[i].first-3600+T;
				return 0;
			}
		}
		if (Otr[i].first+Otr[i+1].second<=3600&&(Otr[i+1].second-Otr[i+1].first+Otr[i].second-Otr[i].first)>T){
			cout << Otr[i+1].first+T-(Otr[i].second-Otr[i].first);
		}
    }
}