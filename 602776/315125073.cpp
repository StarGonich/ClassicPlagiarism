#include <iostream>

using namespace std;

int interract(int stavka, char color){
    int res;
    cout << stavka << " " << color << '\n' << flush;
    cin >> res;
    return res;
}

int main(){
    int res;
    int balance = 210;
    int k = 0;
    int stavk = 1;
    while(balance < 1000){
        cout << balance << endl;
        if(k == 0){
            res = interract(stavk, 'R');
            balance -= stavk;
            if(res == 0){
                k += 1;
                stavk *= 2;
            }
            else if (res == 1){
                k = 0;
                balance += stavk * 2;
                stavk = 1;
            }
            else{
                return 0;
            }
        }
        else if(k == 1){
            res = interract(stavk, 'B');
            balance -= stavk;
            if(res == 0){
                k += 1;
                stavk *= 2;
            }
            else if (res == 1){
                k = 0;
                balance += stavk * 2;
                stavk = 1;
            }
            else{
                return 0;
            }
        }
        else if(k == 2){
            res = interract(stavk, 'R');
            balance -= stavk;
            if(res == 0){
                k += 1;
                stavk = balance;
            }
            else if (res == 1){
                k = 0;
                balance += stavk * 2;
                stavk = 1;
            }
            else{
                return 0;
            }
        }
        else if(k == 3){
            res = interract(stavk, 'B');
            balance -= stavk;
            balance += stavk * 2;
            k = 0;
            stavk = 1;

        }

    }
}
