#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <string>
#include <algorithm>
#include <iterator>
#include <map>
#include <cmath>
#include <bitset>
#include <list>
#include <math.h>
#include <iomanip>
#include <fstream>

# define M_PI           3.14159265358979323846 

using namespace std;

bool comp(long double a, long double b)
{
	if (abs(a - b) < 0.000000001) return 1;
	else return 0;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	vector<int> x(n), d(n), color(n); for (int& i : x) cin >> i; for (int& i : d) cin >> i;
	int k; cin >> k; k--;
	int l = x[k] - d[k], r = x[k] + d[k], ans = 1, cur_l_ind = k - 1, cur_r_ind = k + 1;
	while (true)//могут перепрыгнуть
	{
		bool is_f = 0, is_s = 0;
		while (cur_l_ind >= 0 && x[cur_l_ind] >= l)
		{
			is_f = 1;
			ans++;
			r = max(r, x[cur_l_ind] + d[cur_l_ind]);
			l = min(l, x[cur_l_ind] - d[cur_l_ind]);
			cur_l_ind--;
		}
		if (cur_r_ind < n && x[cur_r_ind] <= r)
		{
			is_s = 1;
			ans++;
			r = max(r, x[cur_r_ind] + d[cur_r_ind]);
			l = min(l, x[cur_r_ind] - d[cur_r_ind]);
			cur_r_ind++;
		}
		if (!is_f && !is_s) break;
	}
	cout << ans;
}

//vector<long long> Tree(300000);
//
//void Update(int ind, long long var)
//{
//	Tree[ind] = var;
//	while (ind != 1)
//	{
//		ind /= 2;
//		Tree[ind] = Tree[ind * 2] + Tree[ind * 2 + 1];
//	}
//}
//
//long long Sum_Tree(int ind, int lt, int rt, int l, int r)
//{
//	if (l <= lt && rt <= r)
//	{
//		return Tree[ind];
//	}
//	if (rt <= l || r <= lt)
//	{
//		return 0;
//	}
//	int mid = (lt + rt) / 2;
//	return Sum_Tree(ind * 2, lt, mid, l, r) + Sum_Tree(ind * 2 + 1, mid, rt, l, r);
//}
//
//long long find_by_count(int ind, int count, int ind_f_el)
//{
//	if (count <= 0) return -1;
//	if (count == 1 && ind >= ind_f_el) return ind - ind_f_el;
//	int ans = -1;
//	ans = max(ans, find_by_count(ind * 2, count, ind_f_el));
//	ans = max(ans, find_by_count(ind * 2 + 1, mid, rt, l, r));
//}



//ios_base::sync_with_stdio(NULL);
//freopen("intersec4.in", "rt", stdin);
//freopen("intersec4.out", "wt", stdout);
//cin.tie(NULL);
//cout.tie(NULL);

//int n, k; cin >> n >> k;

//int indFel = 1;
//while (indFel < n)
//{
//	indFel *= 2;
//}
//for (int i = 1; i <= n; i++)
//{
//	Update(indFel + i - 1, 1);
//}

//int tt = n, step, cur_it = 0;
//while (tt--)
//{
//	if (cur_it + step >= st.size()) { step -= st.size() - cur_it; cur_it = 0; } // mb + 1
//	it = st.begin();
//	advance(it, step);
//	cur_it = distance(st.begin(), it);
//	cout << *it << ' ';
//	st.erase(it);
//	Sum_Tree(1, 0, indFel, cur_it, tt)//кол-во человек после cur_it
//}