#include <iostream>

int main()
{
	int bank = 210;

	int stavka;
	int fails = 0;

	int state = 0;
	while (state != -1 && bank < 1000)
	{
		if (!fails)
			stavka = bank / 14 - 1;
		else if (fails < 3)
			stavka *= 2;
		else
			stavka = bank;
		bank -= stavka;

		std::cout << stavka << " R" << std::endl << std::flush;

		state = std::getchar();
		std::cin.ignore(32767, '\n');
		switch (state)
		{
		case 0:
			fails++;
			break;
		case 1:
			fails = 0;
			bank += stavka * 2;
			break;
		}
	}
}