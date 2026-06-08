#include <bits/stdc++.h>

using namespace std;

int main()
{
    int h1,m1,h2,m2,answ,invers;
    cin >> h1 >> m1 >> h2 >> m2;
    answ=0;
    int prov=0;
    int vsego=44;
    int time1=h1*60+m1,time2=h2*60+m2;
    if (time1>time2) {int z=time2;time2=time1-1;time1=z+1;prov++;}
    if ((time1<=83)and(time2>=83)) answ++;
    if ((time1<=(12*60+34))and(time2>=(12*60+34))) answ++;
    if ((time1<=(23*60+45))and(time2>=(23*60+45))) answ++;
    for (int i=time1/60;i<=time2/60;i++){
        if ((i*60+i>=time1)and(i*60+i<=time2)) answ++;
        invers=i%10*10+i/10;
        if ((i!=22)and(i!=11)and(i*60+invers>=time1)and(i*60+invers<=time2)) answ++;
    }
    if (prov==1) answ=vsego-answ;
    cout << answ;
    return 0;
}
