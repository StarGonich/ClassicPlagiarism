#include <iostream>

using namespace std;

int main(){
    long long cou = 0;
    long long ogr;
    cin>>ogr;
    for(long long int i=0;i<ogr+1;i+=4){
        if(i%5!=0 and i%6!=0)cou+=1;
    }
    for(long long int i=0;i<ogr+1;i+=5){
        if(i%4!=0 and i%6!=0)cou+=1;
    }
    for(long long int i=0;i<ogr+1;i+=6){
        if(i%5!=0 and i%4!=0)cou+=1;
    }
    cout<<cou;
}
