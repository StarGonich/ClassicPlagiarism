#include <iostream>

using namespace std;

int interract(int stavka, char color){
    int res;
    cout << stavka << ' ' << color << endl;
    cin >> res;
    return res;
}

int main(){
    int res;
    int balance = 210;
    int k = 0;
    int stavk = 1;
    while(balance < 1000){
        //cout << balance << endl;
        if(k == 0){
            res = interract(stavk, 'R');
            if(res == 0){
                k += 1;
                balance -= stavk;
                stavk *= 2;
            }
            else{
                k = 0;
                balance += stavk;
                stavk = 1;
            }
        }
        else if(k == 1){
            res = interract(stavk, 'R');
            if(res == 0){
                k += 1;
                balance -= stavk;
                stavk *= 2;
            }
            else{
                k = 0;
                balance += stavk;
                stavk = 1;
            }
        }
        else if(k == 2){
            res = interract(stavk, 'R');
            if(res == 0){
                k += 1;
                balance -= stavk;
                stavk = balance;
            }
            else{
                k = 0;
                balance += stavk;
                stavk = 1;
            }
        }
        else if(k == 3){
            res = interract(stavk, 'R');
            balance *= 2;
            k = 0;
            stavk = 1;

        }

    }
}
