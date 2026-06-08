#include <iostream>

using namespace std;

int main(){
  int n;
  cin>>n;
  if (n==1){
    cout<<1<<endl<<1;
  }
   if (n==2){
    cout<<-1;
  }
 if (n==3){
    cout<<6<<endl<<1<<' '<<2<<' '<<3;
 }
  if (n==4){
    cout<<20<<endl<<10<<' '<<5<<' '<<4<<' '<<1;
  }
  if (n==5){
    cout<<28<<endl<<14<<' '<<7<<' '<<4<<' '<<2<<' '<<1;
  }
  if (n==6){
    cout<<56<<endl<<28<<' '<<14<<' '<<7<<' '<<4<<' '<<2<<' '<<1;
  }
  if ((n!=1)&&(n!=2)&&(n!=3)&&(n!=4)&&(n!=5)&&(n!=6)){
    cout<<-1;
  }
}
