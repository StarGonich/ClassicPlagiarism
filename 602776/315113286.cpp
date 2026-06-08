#include <iostream>
#include<cmath>
using namespace std;

int main()
{

    int bank =210;
    int luss = 0,res, st = bank/16;
    int hod = 0;
    while(true){
           // hod++;
        if(bank >= 1000){
             //   cout << "win " << hod;
            return 0;
        }
        if( luss == 3 ){
            cout << bank << " R"   << endl;
        }else{
            cout << st << " R"  << endl;
        }

        cin >> res;
        if(res == -1){
            cout <<1/0 << endl;
        }
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
