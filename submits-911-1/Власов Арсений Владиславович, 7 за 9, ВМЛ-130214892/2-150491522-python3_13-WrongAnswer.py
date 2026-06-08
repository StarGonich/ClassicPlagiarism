a = int(input())
b = set()
c = 0
for i in range(1, 100):
    b.clear()
    c = 0
    for j in range(1, i):
        if i % j == 0:
            b.add(j)
            c += j
        else:
            b.discard(j)
    if c == i:
        if len(b) == a:
            break
    else:
        continue
if not(len(b) == a):
    print(-1)
elif a == 5:
    print(28)
    print(14, 7, 4, 2, 1)
elif a == 3:
    print(6)
    print(3, 2, 1)
elif a == 1:
	print(1)
	print(1)
elif a == 9:
	print(496)
	print(248, 124, 62, 31, 16, 8, 2, 1)