n, k = int(input()), int(input())
mindel1 = 99999999999999999999999999999999999999999999999
mindel2 = 99999999999999999999999999999999999999999999999
for p in range (n+1, n+k+1):
    for y in range (1, n+1):
        if n / y < mindel1 and (n / y) % 1 == 0 and p / y < mindel2 and (p / y) % 1 == 0:
            mindel1 = n / y
            mindel2 = p / y
            answer = p
print(answer)