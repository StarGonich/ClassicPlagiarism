#include <iostream>
#include<vector>
int main()
{
    int n;
    std::cin >> n;
    std::vector<int> v;
    int pos1, pos2, len1, len2;
    for (int i = 0; i < n; i++)
    {
        int vi;
        std::cin >> vi;
        v.push_back(vi);
    }
    int end1 = 0;
    for (int i = 0; i < n - 1 && v[i] < v[i + 1]; i++)
    {
        end1 = i + 1;
    }
    pos2 = end1 + 1;
    int end2 = n - 1;
    if (v[end1] == v[n - 1])
    {
        std::cout << -1;
    }
    else
    {
        for (int i = pos2; i < n; i++)
        {
            if (v[end1] < v[i])
            {
                end2 = i - 1;
                break;
            }
        }
        for (int i = 0; i < pos2; i++)
        {
            if (v[i] > v[end2])
            {
                pos1 = i;
                break;
            }
        }
        bool flag = true;
        for (int i = 0; i < n - 1 && flag; i++)
        {
            if (!(pos1 <= i <= end2 + 1) && v[i] > v[i + 1]) 
            {
                flag = false;
            }
        }
        if (!flag or v[pos1 - 1] > v[pos2] or (end2 != n - 1 && v[end1] > v[end2 + 1]))
        {
            std::cout << -1;
        }
        else 
        {
            len1 = end1 - pos1 + 1;
            len2 = end2 - pos2 + 1;
            std::cout << pos1 + 1 << ' ' << len1 << '\n' << pos2 + 1 << ' ' << len2;
        }
    }
}
