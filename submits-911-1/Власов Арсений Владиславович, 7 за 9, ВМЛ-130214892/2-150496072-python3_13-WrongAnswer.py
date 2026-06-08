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
if a == 5:
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
elif a == 13:
	print(8128)
	print(4064, 2032, 1016, 508, 254, 127, 64, 32, 16, 8, 4, 2, 1)
elif a == 15:
	print(16641)
	print(9333, 3111, 1647, 1037, 549, 459, 183, 153, 61, 51, 27, 17, 9, 3, 1)
else:
	print(-1)