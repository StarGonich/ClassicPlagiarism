#include <iostream>

using namespace std;

int main()
{
    int h1, h2, m1, m2;
    cin>> h1>>m1>>h2>>m2;
    int s = 0;
    for(int i = h1; i<= h2; i++){
        for(int j = m1; j<=m2;j++){
            if(i == 1 && j ==23){
                s++;
            }else if(i == 12 && j == 34){
                s++;
            }else if(i == 23 && j == 45){
                s++;
            }
            else if(i == j){
                s++;
            }else{
                int a2 = i%10;
                int a1 = i/10;
                int b2 = j%10;
                int b1 = j/10;
                if(a2 == b1 && a1 == b2){
                    s++;
                }
            }
        }
    }
    cout<<s;
    return 0;
}
