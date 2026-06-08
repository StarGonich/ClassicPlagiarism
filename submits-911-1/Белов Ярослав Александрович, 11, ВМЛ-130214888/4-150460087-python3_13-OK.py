n, k =  int(input()), int(input())
de = []
n1 = n
i = 1;
while (i * i <= n1):
    if (n1 % i == 0):
        de.append(n1 // i)
        de.append(i)
    i+=1
de = sorted(de)[::-1]
for i in range(len(de)):
    if (de[i] <= k):
        print(de[i] + n)
        break