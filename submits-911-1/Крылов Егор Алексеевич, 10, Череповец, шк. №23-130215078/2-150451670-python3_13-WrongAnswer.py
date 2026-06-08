n = int(input())
b = []
total = 0
if 1 <= n <= 30:
    a = 0
    while a != n:
        a += 1
        b.append(a)
        total += a
print(total)
all = ""
for i in range(len(b)):
    aa = max(b)
    all += str(aa) + " "
    b.remove(len(b))
print(all)