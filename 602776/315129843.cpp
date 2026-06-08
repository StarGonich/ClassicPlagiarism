#include <iostream>
#include <vector>
int main() {
	int n;
	std::cin >> n;
	int result = n/60*20;
	std::vector<int> plus{4, 5, 6, 8, 10, 15, 16, 18, 25, 28, 32, 35, 42, 44, 45, 50, 52, 54, 55, 56};
	n = n % 60;
	for (int i = 0; i < plus.size()&&n>=plus[i]; i++)
		result++;
	std::cout << result;
	return 0;
}