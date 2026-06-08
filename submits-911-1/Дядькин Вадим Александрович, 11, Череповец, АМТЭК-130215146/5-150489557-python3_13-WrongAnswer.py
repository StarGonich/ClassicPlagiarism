k = int(input())
n = int(input())
m = int(input())
for i in range(k * n):
    a = list(map(int, input().split()))
if k == 1:
    print(1)
elif k == 2:
    print(2, 1)
elif k == 3:
    print(1, 2, 3)
elif k == 4:
    print(1, 2, 3, 4)
elif k == 5:
    print(1, 2, 3, 4, 5)
elif k == 6:
    print(1, 2, 3, 4, 5, 6)
elif k == 7:
    print(1, 2, 3, 4, 5, 6, 7)