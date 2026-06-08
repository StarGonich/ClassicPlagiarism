#include <iostream>
#include <vector>

using namespace std;



int main()
{
    int n;
    cin>>n;
    if(n == 1){
        cout<<2<<"\n"<<2;
        return 0;
    }
    if(n == 2){
        cout<<2<<"\n"<< 1<< " "<< 2;
        return 0;
    }
    if( n == 3){
        cout<<6<<"\n"<< 1<< " "<< 2 << 3;
        return 0;
    }
    n -= 4;
    int k = 6;
    vector<int> otv;
    otv.push_back(1);
    otv.push_back(2);
    otv.push_back(3);
    otv.push_back(6);
    for(int i = 0; i< n; i++){
        k*=2;
        otv.push_back(k);
    }
    if( k <= 1000000000){
        cout<<k*2<<"\n";
    for(auto u: otv){
        cout<<u<<" ";
    }
    }else{
        cout<<-1;
    }


    return 0;
}
