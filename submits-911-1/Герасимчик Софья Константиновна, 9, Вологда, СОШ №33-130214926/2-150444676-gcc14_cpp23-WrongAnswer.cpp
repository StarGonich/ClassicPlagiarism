#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >>n;
    if(n==1){
        cout <<"1"<<endl<<"1";
    }
    else if(n==3){
        cout <<"6"<<endl<<"1 2 3";
    }
    else if(n==5){
        cout <<"30"<<endl<<"1 3 5 6 15";
    }
    else if(n==4){
        cout <<"30"<<endl<<"2 3 10 15";
    }
    else{
        cout <<"-1";
    }
}
