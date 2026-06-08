#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <math.h>

using namespace std;

int main()
{
    int sch = 0;
    int m1,m2,h1,h2;
    cin >> h1 >> m1 >> h2 >> m2;
    if(h1<h2){
    for (int i = h1;i < h2;i++){
        for (int f = 0;f < 60;f++){
            if(h1+i == m1+f){
                sch+=1;
            }
            else if(h1+i == ((m1+f)%10 *10)+int((m1+f)/10)){
                sch+=1;
            }
            else if(int((h1+i)/10)+1==(h1+i)%10 and (h1+i)%10 == int((m1+f)/10)-1 and int((m1+f)/10)+1 == (m1+f)%10){
                sch+=1;
            }
        }
    }
    for (int f = m1;f < m2;f++){
            if(h2 == m1+f){
                sch+=1;
            }
            else if(h2 == ((m1+f)%10 *10)+int((m1+f)/10)){
                sch+=1;
            }
            else if(int(h2/10)+1==h2%10 and h2%10 == int((m1+f)/10)-1 and int((m1+f)/10)+1 == (m1+f)%10){
                sch+=1;
            }
        }
    }
    else if(h1==h2 and m1<m2){
    for (int i = h1;i < h2;i++){
        for (int f = 0;f < 60;f++){
            if(h1+i == m1+f){
                sch+=1;
            }
            else if(h1+i == ((m1+f)%10 *10)+int((m1+f)/10)){
                sch+=1;
            }
            else if(int((h1+i)/10)+1==(h1+i)%10 and (h1+i)%10 == int((m1+f)/10)-1 and int((m1+f)/10)+1 == (m1+f)%10){
                sch+=1;
            }
        }
    }
    for (int f = m1;f < m2;f++){
            if(h2 == m1+f){
                sch+=1;
            }
            else if(h2 == ((m1+f)%10 *10)+int((m1+f)/10)){
                sch+=1;
            }
            else if(int(h2/10)+1==h2%10 and h2%10 == int((m1+f)/10)-1 and int((m1+f)/10)+1 == (m1+f)%10){
                sch+=1;
            }
        }
    }

    cout << sch;
    return 0;