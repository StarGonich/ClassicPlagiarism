#include <iostream>
#include <numeric> gcd
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int h1, h2, m1, m2, k;
    k=0;
    cin >> h1 >> m1 >> h2 >> m2;
    while (h1!=h2 || m1!=m2+1){
        if (h1==m1){
            k+=1;
        }
        else{
            if (h1/10==m1%10 && h1%10==m1/10){
                k+=1;
            }
            else{
                if (h1/10 == h1%10-1 && h1%10 == m1/10-1 && m1/10 == m1%10-1){
                    k+=1;
                }
            }
        }
        m1+=1;
        if (m1==60){
            h1+=1;
            m1=0;
        }
        if (h1==24){
            h1=0;
            m1=0;
        }
    }
    cout << k;
    return 0;
}