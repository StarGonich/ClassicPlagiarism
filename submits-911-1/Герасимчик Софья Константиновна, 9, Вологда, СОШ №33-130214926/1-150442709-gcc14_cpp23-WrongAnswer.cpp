#include <iostream>

using namespace std;

int main()
{
    int h1,m1,h2,m2;
    cin >>h1>>m1>>h2>>m2;
    int v1=h1*60+m1;
    int v2=h2*60+m2;
    int kol=0;
    int a=v1/600;
        int b=(v1/60)%10;
        int c=(v1%60)/10;
        int d=(v1%60)%10;
        if(a*10+b==c*10+d){
            kol+=1;
        }
        else if(a==d && c==b){
            kol+=1;
        }
        else if(a+1==b && b+1==c && c+1==d){
            kol+=1;
        }
    while(v1!=v2){
        v1+=1;
        v1%=3600;
         a=v1/600;
        b=(v1/60)%10;
        c=(v1%60)/10;
        d=(v1%60)%10;
        if(a*10+b==c*10+d){
            kol+=1;
        }
        else if(a==d && c==b){
            kol+=1;
        }
        else if(a+1==b && b+1==c && c+1==d){
            kol+=1;
        }
    }
    cout <<kol;
}
