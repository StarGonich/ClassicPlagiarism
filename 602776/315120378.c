#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n;
    vector<int> coords(n);
    vector<int> range(n);
    vector<bool> blown(n, false);
    for (int i = 0; i < n; i++)
        cin >> coords[i];
    for (int i = 0; i < n; i++)
        cin >> range[i];
    cin >> k;
    k--;
    int c = 1;
    vector<int> visit;
    visit.push_back(k);
    while (not visit.empty()){
        blown[visit[0]] = true;
        for (int i = 0; i < n; i++){
            if ((not blown[i]) & (abs(coords[i] - coords[visit[0]]) <= range[visit[0]])){
                visit.push_back(i);
                c++;
                }
        }
        visit.erase(visit.begin());
    }
    cout << c;
}
