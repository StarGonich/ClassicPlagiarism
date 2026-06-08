n = int(input())

#сумма всех натуральных чисел  n
#по условию m
all = n * (n + 1) // 2 

if all>10000000000:
    print(-1) #нету ответов
else:

    print(all) #m
    print(*range(1, n + 1)) #все делитили (сумма m)