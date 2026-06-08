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

int main()//случай: была ли отсорт + повт эл???
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	vector<int> a(n); for (int& i : a) cin >> i;
	int graphic_falls = 0, ind_gr_fl = -1;
	for (int i = 1; i < n; i++)
	{
		if (a[i] < a[i - 1]) { graphic_falls++; ind_gr_fl = i; }
	}
	if (graphic_falls != 1) { cout << -1; return 0; }
	int pos1 = ind_gr_fl - 1, len1, pos2 = ind_gr_fl, len2;//потом pos1 + 1, pos2 + 1
	for (int i = ind_gr_fl - 1; i >= 0; i--)
	{
		if (a[i] < a[pos2]) break;
		pos1 = i;
	}
	len1 = pos2 - pos1;
	len2 = 1;
	for (int i = ind_gr_fl + 1; i < n; i++)
	{
		if (a[i] > a[pos1]) break;
		len2++;
	}
	//проверка если начало сходится, а концы не подойдут 1 3 5 2 4  конец правого отрезка(перед swap-ом) должен быть меньше начала первого(перед swap-ом)
	//проверка заключается в том, что мы смотрим на элемент с индексом (pos2 + len2 + 1) и смотрим на конечный в первом отрезке и если конеч в первом отрезке больше, то выводим -1
	if (pos2 + len2 < n && a[pos1 + len1 - 1] > a[pos2 + len2]) cout << -1;
	else cout << pos1 + 1 << ' ' << len1 << '\n' << pos2 + 1 << ' ' << len2;
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