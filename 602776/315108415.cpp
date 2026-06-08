#include <iostream>
#include <vector>
int main()
{
	class Turple
	{
	public:
		Turple() {};
		Turple(int a, int b,int max) {
			pos = a; len = b; this->max = max;
		};
		~Turple() {};
		int pos = 0,len=0,max=0;
	};
	int n,temp;
	std::cin >> n;
	std::vector<int>a;
	std::vector<Turple>turples;
	std::cin >> temp;
	Turple p = Turple(0, 1, temp);
	for (int i = 0; i < n-1; i++)
	{
		std::cin >> temp;
		if (temp == p.max + 1)
		{
			p.len++; p.max++;
		}
		else {
			turples.push_back(p);
			p.pos = p.pos + p.len;
			p.max = temp;
			p.len = 1;
		}
	}
	turples.push_back(p);
	if (turples.size()>3 || turples.size() <= 1)
	{
		std::cout << -1;
		return 0;
	}
	if (turples.size()==2)
	{
		std::cout << turples[1].pos + 1 << " " << turples[1].len << std::endl; 
		std::cout << turples[0].pos + 1 << " " << turples[0].len << std::endl;
		return 0;
	}
	if (turples[1].max>turples[2].max&&turples[2].max>turples[0].max)
	{
		std::cout << turples[1].pos + 1 << " " << turples[1].len << std::endl;
		std::cout << turples[2].pos + 1 << " " << turples[2].len << std::endl;
		return 0;
	}
	if (turples[2].max > turples[0].max && turples[0].max > turples[1].max)
	{
		std::cout << turples[0].pos + 1 << " " << turples[0].len << std::endl;
		std::cout << turples[1].pos + 1 << " " << turples[1].len << std::endl;
		return 0;
	}
	if (turples[0].max > turples[1].max && turples[1].max > turples[2].max)
	{
		std::cout << turples[0].pos + 1 << " " << turples[0].len << std::endl;
		std::cout << turples[2].pos + 1 << " " << turples[2].len << std::endl;
		return 0;
	}
}