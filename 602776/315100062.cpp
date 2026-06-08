#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	long long N, otvet = 0;
	std::cin >> N;

	long long vse = (N / 60);
	long long first = (N / 4)-(N/12)-(N/20)+ vse;
	long long second = (N / 5) - (N / 30) - (N / 20) + vse;
	long long third= (N / 6) - (N / 12) - (N / 30) + vse;
	std::cout <<first+second+third;

}