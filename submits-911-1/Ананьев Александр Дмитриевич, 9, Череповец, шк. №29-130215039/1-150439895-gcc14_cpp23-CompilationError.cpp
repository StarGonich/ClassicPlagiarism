#include <iostream>
using namespace std;
int main(){
int n,m,i,h1,h2,m1,m2;

cin>>h1>>h2>>m1>>m2;
n=h1+m1;
m=h2+m2;
for(int p=n;p<=m;i++){
if(h1==m1&&h2==m2){
    i++;
    }if(h1==m2&&m1==h2){
i++;
    }if(h1+1==h2&&h2+1==m1&&m1+1==m2){
i++;
    }if(h1==h2&&m1==m2){
i++;
    }
}
cout<<i<<" "<<endl;