#include <iostream>
#include <string>
#include <vector>
using namespace std;

int func(int a){
	vector<string> b = {};
	int ras = 0, cnt=0, res = 0;
	while (a >= 1){
    	cnt = a%10;
    	b.push_back(to_string(cnt));
		a /= 10;
        ras+=1;
    }
	for (int i = 1; i < pow(10, ras); i*=10){
		res+= i * stoi(b[i]);
    }
	return res;
}

int main(){
	int h1, h2, m1, m2, res;
	for (int i = h1; i <= h2. i++){
    	for (int j = m1; j <= m2; j++){
            if (j = i || j=func(i) || j = i+22){
                res+=1;
            }
            if (j > 59){
                i++;
        		j = 0;
                break;
            }
            j++;
    }
    cout << res;
}