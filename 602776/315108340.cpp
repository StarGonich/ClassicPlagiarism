#include <iostream>
#include<cmath>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> tmp(n);
	bool flag = true;
	vector<pair<int, int>> otrezocs;
	for (int i = 0; i < n;++i) {
		cin >> tmp[i];
		if (i > 0 && flag && tmp[i] - tmp[i - 1] != 1) {
			flag = false;
		}
	}

	if (flag) {
		cout << "-1";
		return 0;
	}
	int start=0, end=n;
	for (int i = 0; i < n-1;++i) {
		if (tmp[i + 1] - tmp[i] != 1) {
			end = i;
			otrezocs.push_back({start,end});
			start = i+1;
		}
		if (i == n - 2) {
			otrezocs.push_back({ start,n-1 });
		}
		
	}
	int max_i = 1;
	vector<pair<int, pair<int, int>>> shaker;
	for (int i = 0; i < otrezocs.size(); ++i) {
		for (int j = 0; j < otrezocs.size(); ++j) {
			if (tmp[otrezocs[j].first] == max_i) {
				shaker.push_back({ j,{otrezocs[j].first,otrezocs[j].second}});
				max_i = tmp[otrezocs[j].second] + 1;
				break;
			}
		}
	}
	for (int i = (int)shaker.size()-1; i >=0; --i) {
		if (shaker[i].first!=i) {
			cout << shaker[i].second.first + 1<<" " << shaker[i].second.second - shaker[i].second.first + 1 << endl;
		}
	}
}