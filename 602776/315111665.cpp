#include <iostream>
#include<cmath>
using namespace std;

int main()
{

    int bank =210;
    int luss = 0,res, st = bank/16;
    while(true){
        if(bank >= 1000){
            return 0;
        }
        if( luss == 3 ){
            cout << bank << " R"   << endl;
        }else{
            cout << st << " R"  << endl;
        }

        cin >> res;
        if(res == 0){
            luss++;
            bank-=st;
            st*=2;
        }else{
            luss =0;
            bank+=(st*2);
            st = bank/16;
        }

    }
}
