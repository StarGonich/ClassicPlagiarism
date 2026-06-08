#include <iostream>

using namespace std;

int main(){
int i,a,m,d1,d2,d3;
cin>>a;
m=a*2;
cout<<m<<"\n"<<endl;
for (i = m; i > 0; i--) {
      if (m%i==0)  {
       cout<< i <<endl ;
      }
    }
}
