#include <iostream>

using namespace std;

int main()
{
    int funti = 210;
    int kol = 0;
    int stavka = funti / 15;
    for (int i = 0; i < 100; i++){
        if (kol == 3){
            cout << funti << " " << "R" << endl;
            int vod;
            cin >> vod;
            funti *= 2;
            kol = 0;
            stavka = funti / 15;
            if (funti >= 1000)
                break;
        }
        else{
            if (kol != 0)
                stavka *= 2;
            cout << stavka << " " << "R" << endl;
            int vod;
            cin >> vod;
            if (vod == 0){
                kol += 1;
                funti -= stavka;
                if (funti <= 0)
                    break;
            }
            else{
                kol = 0;
                funti += (2 * stavka);
                stavka = funti / 15;
                if (funti >= 1000)
                    break;
            }
        }
    }
}
