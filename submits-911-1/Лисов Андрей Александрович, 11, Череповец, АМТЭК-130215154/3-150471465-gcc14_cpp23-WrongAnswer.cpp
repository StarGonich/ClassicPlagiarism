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
