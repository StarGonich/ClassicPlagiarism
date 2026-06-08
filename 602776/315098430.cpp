#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	long long N, otvet = 0;
	cin >> N;
	long long vse = (N / 60);
	long long first = (N / 4)-(N/12)-(N/20)- (N / 60);
	long long second = (N / 5) - (N / 30) - (N / 20) - (N / 60);
	long long third= (N / 6) - (N / 12) - (N / 30) - (N / 60);
	cout <<first+second+third;

}