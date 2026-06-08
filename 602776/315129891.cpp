#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> chisla (n);
    for (int i = 0; i < n; i++)
        cin >> chisla[i];
    int pos1, pos2, len1 = 0, len2 = 0;
    int i = 0;
    int flag = 1, kol = 0, otvet = 0, schet = 0;
    for (i; i < n; i++){
        if (chisla[i] != (i+1)){
            if (kol > 0){
                cout << -1;
                otvet += 1;
                break;
            }
            else{
                pos1 = i+1;
                int ch = chisla[i];
                for (int j = i+1; j<n; j++){
                    len1 += 1;
                    if (chisla[j] != (ch+1)){
                        pos2=j+1;
                        int ch2 = chisla[j];
                        if (j + 1 == n){
                            len2 += 1;
                            i = j + 1;
                            break;
                        }
                        else{
                            for(int l = j+1; l < n; l++){
                                len2+=1;
                                if (chisla[l] != (ch2+1)){
                                    flag = 0;
                                    kol += 1;
                                    i = l;
                                    break;
                                }
                                else
                                    ch2 += 1;
                            }
                        }
                    }
                    else{
                        ch += 1;
                    }
                    if (flag == 0)
                        break;
                }
            }
        }
        schet += 1;
    }
    if (schet == n)
        cout << -1;
    else if (otvet == 0){
        cout << pos1 << " " << len1 << endl << pos2 << " " << len2;
    }
}
