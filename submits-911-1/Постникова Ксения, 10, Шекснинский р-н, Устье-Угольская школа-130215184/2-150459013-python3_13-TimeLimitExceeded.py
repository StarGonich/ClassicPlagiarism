a = int(input())
c = 1
sum = 0
while  c <= a:
    if a % c == 0:
        sum = sum + c
c = c + 1
print ( sum )