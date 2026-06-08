#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int n;
    cin >>n;
    if(n==1){
        cout <<"1"<<endl<<"1";
    }
    if(n==2){
        cout <<"-1";
    }
    vector <int> res={6, 1, 2, 3};
    for(int i=4; i<=n; i++){
        res.push_back(res[0]);
        res[0]*=2;
    }
    cout <<res[0]<<endl;
    for(int i=1; i<=n; i++){
        cout <<res[i]<<" ";
    }
}
