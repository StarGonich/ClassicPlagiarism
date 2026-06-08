#include <iostream>

int main()
{
	long long n;
	std::cin >> n;

	long long count = n / 60;
	count *= 20;

	for (long long i = n; i > (n / 60) * 60; i--)
	{
		if (i % 20 == 0 || i % 12 == 0 || i % 30 == 0)
			continue;
		if (i % 4 == 0 || i % 5 == 0 || i % 6 == 0)
		{
			count++;
			continue;
		}
	}

	std::cout << count;
}