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

bool comp(long long a, long long b)
{
	if (a == b) return 1;
	else return 0;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	long long a, b, p; cin >> a >> b >> p;
	long long c, d, q; cin >> c >> d >> q;
	long double q1, q2;
	bool otl_v_k_raz = 0, nepr_otl_v_k_raz = 0, tolko_q2 = 0, nepr_tolko_q2 = 0, tolko_q1 = 0, nepr_tolko_q1 = 0;

	if (!a && !c && d && b)
	{
		tolko_q2 = comp(b * q, p * d);
		nepr_tolko_q2 = !comp(b * q, p * d);
	}
	if (a && c && !d && !b)
	{
		tolko_q1 = comp(a * c, p * q);
		nepr_tolko_q1 = !comp(a * c, p * q);
	}

	if (a != 0 && d != 0) otl_v_k_raz = comp(a * d, b * c) && comp(b * q, p * d);
	if (a != 0 && d != 0) nepr_otl_v_k_raz = comp(a * d, b * c) && !comp(b * q, p * d);

	if (tolko_q1 || tolko_q2 || otl_v_k_raz) cout << "Ambiguity"; // a == c && b == d && p == q 
	else if (nepr_tolko_q1 || nepr_tolko_q2 || !a && !b || !c && !d || nepr_otl_v_k_raz) cout << "Contradiction";// a == c && b == d && p != q
	else
	{
		long double k;
		if (c)
		{
			k = (long double)a / c;
			q2 = (p - q * k) / (b - d * k);
			if (a)
			{
				q1 = (p - b * q2) / a;
			}
			else
			{
				q1 = (q - d * q2) / c;
			}
		}
		else
		{
			k = (long double)b / d;
			q1 = (p - q * k) / (a - c * k);
			if (b)
			{
				q2 = (p - a * q1) / b;
			}
			else
			{
				q2 = (p - c * q1) / d;
			}
		}
		if (q1 < 0 || q2 < 0) cout << "Not positive";
		else
		{
			cout << "Success\n" << q1 * 100 << ' ' << q2 * 100;
		}
	}
}
