#include <iostream>
#include <vector>
int main() {
	int badCount = 0;
	int gameresult; int summ = 210;
	int gameMoney = 0;
	double win = 0.3;
	gameMoney = summ * win;
	std::cout << gameMoney << " R" << std::endl;
	std::cin >> gameresult;
	while (true)
	{
		switch (gameresult)
		{
		case -1:
			return 0;
		case 0:
			summ -= gameMoney;
			badCount++;
			if (win >= 0.15)
				win -= 0.05;
			else
				win = 0.1;
			if (badCount == 3)
			{
				gameMoney = summ;
				std::cout << gameMoney << " R" << std::endl;
			}
			else {
				gameMoney = summ * win;
				std::cout << gameMoney << " R" << std::endl;
			}
			std::cin >> gameresult;
			break;
		case 1:
			summ += gameMoney;
			if (win<=0.3)
				win += 0.1;
			else
				win = 0.4;			
			badCount = 0;
			gameMoney = summ * win;
			std::cout << gameMoney << " R" << std::endl;
			std::cin >> gameresult;
			break;
		default:return 0;
		}
	}
}