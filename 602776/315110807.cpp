#include <iostream>

using namespace std;

int main()
{
    int funti = 210;
    for (int i = 0; i < 100; i++){
        int kol = 0;
        int stavka;
        char cvet;
        cin >> stavka >> cvet;
        cout << stavka << " " << cvet << endl;
        int vod;
        if ((stavka > funti) || ((cvet != 'R') && (cvet != 'B'))){
            cin >> vod;
            break;
        }
        else if (kol < 3){
            cin >> vod;
            if (vod < 0){
                kol += 1;
                funti -=stavka;
                if (funti == 0)
                    break;
            }
            else{
                kol = 0;
                funti += (2 * stavka);
                if (funti >= 1000)
                        break;
            }
        }
        else{
            cin >> vod;
            kol = 0;
            funti += (2 * stavka);
                if (funti >= 1000)
                        break;
        }
    }
}
