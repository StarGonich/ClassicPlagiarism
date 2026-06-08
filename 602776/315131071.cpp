#include <iostream>

using namespace std;

int main()
{
    int sum = 210, c = 0, res, stav;
    stav = sum / 16;
    while (true){
        cout << stav << " R" << endl;
        cin >> res;
        if (res){
            sum += stav;
            stav = sum / 16;
        }
        else{
            sum -= stav;
            stav *= 2;
        }
        if (sum >= 1000){
            return 0;
        }
    }
}
