#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    double a1,a2, b2, b1, z1, z2;
    cin >> a1 >>b1>>z1;
    cin >> a2 >>b2 >>z2;
if(a1 == 0 && a2 ==0){
    if( b1/b2 != z1/z2  ){
    cout << "Contradiction";
        return 0;
    }

if( b1/b2 == z1/z2 ){
cout << "Ambiguity";
        return 0;
    }
}
if(b1 == 0 && b2 ==0){
    if( a1/a2 != z1/z2  ){
    cout << "Contradiction";
        return 0;
    }

if( a1/a2 == z1/z2 ){
cout << "Ambiguity";
        return 0;
    }
}
if( a1/a2 == b1/b2 && a1/a2 != z1/z2  ){
    cout << "Contradiction";
        return 0;
    }

if(a1/a2 == b1/b2 && a1/a2 == z1/z2 ){
cout << "Ambiguity";
        return 0;
    }
    double x, y;
    if(a1 == 0){
         y = z1/b1;
     x = (z2 - y*b2)/a2;
    }else{
        y = (z2-(a2*z1/a1))/(b2 - (a2*b1)/a1) ;
     x = (z1 - y*b1)/a1;
    }
    //double y = (z2-(a2*z1/a1))/(b2 - (a2*b1)/a1) ;
    //double x = (z1 - y*b1)/a1;


    if(x < 0 || y <0){
        cout << "Not positive";
        return 0;
    }
    cout << "Success\n";
    cout << x*100<<" " << y*100;
}
