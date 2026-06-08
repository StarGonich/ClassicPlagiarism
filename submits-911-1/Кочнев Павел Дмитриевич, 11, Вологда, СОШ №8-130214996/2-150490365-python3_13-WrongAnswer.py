a = int(input())
if a == 1:
    print(1)
    print(1)
elif a == 2:
    print(6)
    print(1, 2, 3)
elif a == 3:
    print(12)
    print(3, 4, 6)
elif a == 4:
    print(24)
    print(1, 3, 8, 12)
elif a == 4:
    print(24)
    print(1, 3, 8, 12)
elif a == 5:
    print(48)
    print(1, 3, 8, 12, 24)
else:
    c = 3 *(2**(a - 1))
    b = []
    for i in range(a - 1):
        b.append(2**1)
    b.append(c - sum(b))
    print(c)
    print('',(map(str, b)))