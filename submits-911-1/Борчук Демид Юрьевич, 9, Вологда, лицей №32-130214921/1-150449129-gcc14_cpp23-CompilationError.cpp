#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    float h1, m1, h2,m2,c=0;
    cin>>h1>>m1>>h2>>m2;
    if (h2<h1){
        swap(h2, h1);
    }
    if(m2<m1){
        swap(m2, m1);
    }
    while(h1 < h2 || m1 <m2){
      if(h1== m1){
        c++;
      }
      else if(h1/10 == m1%10 && h1%10==m1/10){
        c++;
      }
      else if(h1/10==h1%10+1 && h1 %10 +1== m1/10+1 && m1/10+1 == m2%10+1){
        c++;
      }
    m1++;
    if(m1>=60){
        h1++;
        m1-=60;
    }
    }
    cout<<c;
    return 0;
}
