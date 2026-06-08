#define _USE_MATH_DEFINES
#include <iostream>
#include <ios>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>

#define int long long
#define ll unsigned long long
#define nl "\n"



using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int one_ind = -1;
	int con_ind = n-1;
	for (int i = 0; i < n-1; i++) {
		if (arr[i] == 1) {
			one_ind = i;
		}
		if (one_ind != -1) {
			if (abs(arr[i] - arr[i + 1]) != 1 || arr[i] > arr[i + 1]) {
				con_ind = i;
				break;
			}
		}
	}


	if (one_ind != 0) {
		bool gg = true;
		vector<int> check(n);
		int ind = 0;
		for (int i = one_ind; i <= con_ind; i++) {
			check[ind] = arr[i];
			ind++;
		}
		for (int i = 0; i < one_ind; i++) {
			check[ind] = arr[i];
			ind++;
		}
		for (int i = con_ind + 1; i < n; i++) {
			check[ind] = arr[i];
			ind++;
		}

		for (int i = 0; i < n - 1; i++) {
			if (check[i] > check[i + 1]) {
				gg = false;
				break;
			}
		}

		if (gg) {
			cout << 1 << " " << one_ind << nl << one_ind + 1 << " " << con_ind - one_ind + 1 << nl;
		}
		else {
			cout << -1 << nl;
		}
	}
	else {
		if (con_ind == n - 1) {
			cout << -1 << nl;
		}
		else {
			int bb = -1;
			for (int i = con_ind+1; i < n - 1; i++) {
					if (abs(arr[i] - arr[i+1]) != 1 || arr[i] > arr[i+1]) {
						bb = i;
						break;
					}
			}
			int first = arr[con_ind + 1];
			
			bool gg = true;
			vector<int> check(n);
			int ind = 0;
			for (int i = one_ind; i <= con_ind; i++) {
				check[ind] = arr[i];
				ind++;
			}
			for (int i = arr[con_ind + 1] - 1; i <= arr[bb] - 1; i++) {
				check[ind] = arr[i];
				ind++;
			}
			for (int i = arr[con_ind+1]; i <= arr[bb]; i++) {
				check[ind] = i;
				ind++;
			}
			for (int i = bb+ (bb - con_ind) + 1; i < n; i++) {
				check[ind] = arr[i];
				ind++;
			}

			for (int i = 0; i < n - 1; i++) {
				if (check[i] > check[i + 1]) {
					gg = false;
					break;
				}
			}

			if (gg) {
				cout << con_ind + 2 << " " << (bb - (con_ind+1) + 1) << " " << arr[con_ind + 1] << " " << (arr[bb] - arr[con_ind + 1] + 1 )<< nl;
			}
			else {
				cout << -1 << nl;
			}
		}


	}
	

}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);

	int tests = 1;
	while (tests--) {
		solve();
	}

	return 0;
}
