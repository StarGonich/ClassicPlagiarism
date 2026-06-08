#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int func(int a){
	vector<string> b = {};
	vector<string> rev = {};
	int ras = 0, cnt=0, res = 0;
	while (a > 1){
    	cnt = a%10;
    	b.push_back(to_string(cnt));
    	cnt=0;
		a /= 10;
        ras+=1;
    }
    cnt = b.size()-1;
    for (int i = cnt; i>=0; i++){
        rev.push_back(b[i]);
    }
    cnt = 0;;
	while (ras>-1 && cnt < rev.size()){
		res += stoi(rev[cnt]) * pow(10,ras-1);
		ras--;
		cnt++;
    }
	return res;
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
	if (h1 == h2 && m1 == m2){
		res = 0;
    }
    cout << res;
}