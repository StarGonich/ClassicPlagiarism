a = int(input())
b = a*2
print(b)
for x in range(1, b+1):
    if b % x == 0:
        print(x, end='')


