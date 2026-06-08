#include <iostream>
#include <vector>
using namespace std;

int summa(vector<int> sum{}){
    int res = 0;
    for (int i = 0; i < sum.size(); i++){
        res+=sum[i];
    }
    return res;
}

int main(){
    bool flag = true;
	vector<int> str{};
	int n;
	cin >> n;
	int res = 1, cnt=0;
	while (flag){
    	for (int i = 1; i < res+1; i++){
        	if (res%i == 0){
        		cnt +=1;
        		str.push_back(i);
        	}
    	}
		if (cnt == n){
            if (summa(str) == res){
                flag = false;
            }
        }
	res+=1;
	}
	if (n == 0){
        res = 1;
        str = {0};
	}
    cout << res-1 << endl;
	for (int i = 0; i < str.size(); i++){
		cout << str[i] << ' ';
	}
}