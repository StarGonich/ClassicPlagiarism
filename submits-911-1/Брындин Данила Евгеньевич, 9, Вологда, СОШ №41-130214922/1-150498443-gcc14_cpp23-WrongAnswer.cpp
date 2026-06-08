#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int func(int a){
	string b;
	int ras = 0, cnt=0, res0 = 0;
	while (a > 1){
    	cnt = a%10;
    	b+=(to_string(cnt));
    	cnt=0;
		a /= 10;
    }
    res0 = stoi(b);
	return res0;
}

int main(){
	int h1, m1, h2, m2, res=0, tekh, tekm;
	cin >> h1 >> m1 >> h2 >> m2;
	tekh = h1;
	tekm = m1;
	while (tekh!=h2 && tekm != m2){
        if (tekm == tekh || tekm==func(tekh) || tekh == tekm+22){
            res+=1;
        }
        tekm++;
        if (tekm > 59){
            tekm = 0;
            tekh++;
        }
    }
    cout << res;
}