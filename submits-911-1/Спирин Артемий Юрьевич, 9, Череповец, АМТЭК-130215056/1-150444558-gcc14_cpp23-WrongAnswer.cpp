#include <iostream>

using namespace std;

int main(){
long long h1,m1,h2,m2;
cin>>h1>>m1>>h2>>m2;
if ((h1==h2)&&(m1==m2)){
    if (h1==m1){
        cout<<1;
    } else if ((((h1/10)*10)+(h1/10))==m1){
        cout<<1;
    } else if ((h1/10) == ((h1%10)+1) == ((m1/10)+2) == ((m1%10)+3)){
        cout<<1;
    }else {
    cout<<0;
    }
} else {
    long long rr=0;
    long long m11=m1;
    long long h11=h1;
    int d=0;
    if ((h1<h2)||((h1==h2)&&(m1<m2))){
    while ((h11<h2)||((h11==h2)&&(m11<=m2))){
    if (h11==m11){
        rr++;
    } else if ((((h11/10)*10)+(h11/10))==m11){
        rr++;
    } else if ((h11/10) == ((h11%10)+1) == ((m11/10)+2) == ((m11%10)+3)){
        rr++;
    }
    m11++;
    if (m11==60){
        m11=0;
        h11++;
    }
    if (h11==24){
        h11=0;
        d=1;
    }
    }
    } else {
     while ((h11<h2)||((h11==h2)&&(m11<=m2))||(d==0)){
    if (h11==m11){
        rr++;
    } else if ((((h11/10)*10)+(h11/10))==m11){
        rr++;
    } else if ((h11/10) == ((h11%10)+1) == ((m11/10)+2) == ((m11%10)+3)){
        rr++;
    }
    m11++;
    if (m11==60){
        m11=0;
        h11++;
    }
    if (h11==24){
        h11=0;
        d=1;
    }
    }
    }
    cout<<rr;
}
}