#include <iostream>

using namespace std;

int main()
{
    int h1;
    int m1;
    int h2;
    int m2;
    cin >> h1;
    cin >> m1;
    cin >> h2;
    cin >> m2;
    int cou = 0;
    for (int i=h1; i<=h2; ++i){
        for (int j=m1; j<=m2; ++j){
            if (j=60&&i<h2) {
                j = 0;
            }
            if (j == i/10+ (i%10)*10) {
                cou++;
            }
            if (j == i) {
                cou++;
            }
            if ((i == 1&& j == 23)||(i == 12 && j ==34)|| (i==23 && j == 45)) {
                cou++;
            }
        }
    }
    cout << cou;
}