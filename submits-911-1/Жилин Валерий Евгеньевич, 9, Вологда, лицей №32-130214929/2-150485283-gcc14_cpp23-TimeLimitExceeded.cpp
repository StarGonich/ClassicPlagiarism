#include <stdio.h>
#include <stdint.h>

#ifdef DEBUG
#define debug if (1)
#else
#define debug if (0)
#endif

int
main (void)
{
	uint64_t arr[32] = {0};
	uint64_t N = 1, K, *it;
	scanf("%lu", &K);

	if (K & 1 == 0)
	{
		printf("-1\n");
		return 0;
	}

	for (;;)
	{
		it = arr;
		uint64_t cur = 1;
		uint64_t tmp = N;
		uint64_t j = 2;

		for (; j * j < N; ++j)
		{
			debug
			{
				if (N < 25) printf("%lu %lu %lu\n", N, cur, j);
				else return 0;
			}

			if (N % j == 0)
			{
				cur += 2;
				*it = j;
				it += 1;
				*it = N/j;
				it += 1;
			}
		}

		j += 1;

		if (j * j == N)
		{
			cur += 1;
			*it = j;
			it += 1;
		}

		*it = 0;

		if (cur == K)
		{
			printf("%lu\n1 ", N);
			for (uint64_t *p = arr; p < it; ++p)
			{
				printf("%lu ", *p);
			}
			putchar('\n');
			return 0;
		}
		N += 1;
	}
	printf("-1\n");
}

/*
Найдите натуральное число в диапазоне от 1 до 10^9, равное сумме каких-то n
своих делителей (выбранные делители должны быть различны между собой).

Формат ввода
Вводится одно целое число n ( 1≤n≤30, 1≤n≤30).

Формат вывода
В первой строке выходных данных выведите искомое число m. Во второй строке
выведите n различных натуральных чисел — делителей числа m, сумма которых
равна m. Делители можно выводить в любом порядке. Если есть несколько
правильных ответов, выведите любой. Если решения нет, выведите -1.
*/
