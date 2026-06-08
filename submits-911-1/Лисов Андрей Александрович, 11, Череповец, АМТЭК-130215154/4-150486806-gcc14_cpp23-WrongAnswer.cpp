/*
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, t, fp, sp;
    bool flag; flag = true;
    sp = 0; fp = -1;
    cin >> n >> t;
    vector <bool> q;
    for (int i = 0; i < n; i++)
    {
        int start, finish;

        cin >> start >> finish;
        for (int j = fp+1; j < start; j++)
        {
            q.push_back(false);
        }
        for (int j = start; j <= finish; j++)
        {
            q.push_back(true);
        }
        sp = start;
        fp = finish;
    }
    int currSum;
    currSum = 0;
    int konec, bim;
    bim = 0;
    if (fp < 3600) konec = fp; else konec = 3600;
    //cout << "!konec " << konec << endl;
    for (int i = 0; i < konec; i++)
    {
        currSum += q[i];
    }
    //cout << "! " << currSum << "\n";
    while (bim + 3599 < fp)
    {
        //cout << "! " << currSum << endl;
        if (currSum > t)
        {
            cout << bim << "\n";
            flag = false;
            break;
        } else
        {
            currSum -= q[bim];
            currSum += q[bim + 3599];
            bim++;
        }
    }
    if (flag)
    {
        cout << "-1\n";
    }
    return 0;
}


#include <iostream>
#include <numeric>

int main()
{
    std::cout << ::lcm(6, 9);
    return 0;
}
*/
#include <iostream>
using namespace std;

int nod(int n1, int n2) {
  while (n2 != 0) {
    int tmp = n2;
    n2 = n1 % n2;
    n1 = tmp;
  }
  return n1;
}

int lcm(int n1, int n2) {
  int gcd = nod(n1, n2);
  return (n1 * n2) / gcd;
}

int main()
{
    long int n, k, bim;
    cin >> n >> k;
    unsigned long int minLcm = 1000000000001;
    long int ans  = -1;
    for (long int p = n + 1; p <= n + k; p++)
    {
        bim = lcm(n, p);
        //cout << "! " << bim << endl;
        //cout << "! " << minLcm << endl;
        if (bim < minLcm)
        {
            minLcm = bim;
            ans = p;
        }
        //cout << "! " << bim << endl;

    }
    cout << ans<< endl;
    return 0;
}
