#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> t1;
    vector<int> t2;
    while(n--)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        t1.push_back(temp1);
        t2.push_back(temp2);
    }
    vector <bool> time(t2[t2.size()-1]+1, false);
    for(int i = 1; i < t1.size()+1; i++)
    {
        for(int j = t1[i]; j <= t2[i]; j++)
        {
            time[j] = true;
        }
    }
    for(int i = 1; i < time.size()-3600; i++)
    {
        int sumr = 0;
        for(int j = i; j < i + 3600; j++)
        {
            if(time[j])
            {
                sumr++;
            }
        }
        if(sumr >= t+1)
        {
            cout << i+1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}