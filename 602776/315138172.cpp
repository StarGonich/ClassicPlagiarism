#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <math.h>

typedef long long ll;
typedef long double ld;
#define pll pair<ll,ll>  
#define pii pair<int,int>  

const ld EPS = 1e-6;
const ld EPS2 = 1e-1;
using namespace std;

void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll t = 1;
	//cin >> t;
	while (t--) solve();
}

ll csount = 0;
ll zapr(ll stavka, string cv) {
	cout << stavka << " " << cv << endl;
	ll m; cin >> m;

	
	return m;
}

void solve() {
	srand(52);
	
	ll summa = 210;
	ll stavka = summa / 10;
	ll cnt = 0;
	ll m = 0;
	while(true)
	{
		ll chance = rand() % 2;
		ll res = -1;
		if(chance == 0) res = zapr(stavka, "R");
		else res = zapr(stavka, "B");
		cnt++;
		if(res == 1)
		{
			summa += stavka;
			stavka = summa/10;
		}
		if(res == 0)
		{
			summa -= stavka;
			stavka *= 2;
		}
		
		if (summa > 1000) break;
		if (cnt == 100) break;
	}
}