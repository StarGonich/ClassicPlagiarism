n = int(input())
t = int(input())
s = [0] * (10 ** 9)
b = 0
k = 0
for i in range(n):
    t1, t2 = map(int, input().split())
    for j in range(t1, t2):
        s[j] = 1
for i in range(3600):
    k += s[i]
for i in range(3600, 10 ** 9):
    if k > t:
        print(i - 3600)
        b = 1
        break
    if s[i - 3600] == 0:
        k += s[i]
    else:
        k += s[i] - 1
if b == 0:
    print(-1)