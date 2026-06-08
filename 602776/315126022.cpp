#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    int ind = 1;
    vector<int> pos;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    for (int i = 0; i < n; i++){
        if (nums[i] != ind){
            pos.push_back(i);
            ind = nums[i];
        }
        ind++;
    }
    //for (int i = 0; i < pos.size(); i++)
    //    cout << pos[i] << " ";
    //cout << endl;
    if (pos.size() == 2){
        cout << 0 << " " << pos[1] << endl;
        cout << pos[1] + 1 << " " << n;
    }
    else if (pos.size() == 3){
        cout << pos[0] + 1 << " " << pos[1] - pos[0] << endl;
        cout << pos[1] + 1 << " " << pos[2] - pos[1];
    }
    else if (pos.size() == 4){
        cout << pos[0] + 1 << " " << pos[1] - pos[0] << endl;
        cout << pos[2] + 1 << " " << pos[3] - pos[2];
    }
    else{
        cout << -1;
    }
}
