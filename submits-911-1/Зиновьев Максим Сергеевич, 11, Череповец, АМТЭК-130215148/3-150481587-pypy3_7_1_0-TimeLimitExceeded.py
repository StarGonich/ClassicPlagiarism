n = int(input())
t = int(input())
a = ['0'] * 1003600
b = []
y = -1
for i in range(n):
    t1, t2 = map(int, input().split())
    for i in range(t1, t2):
        a[i] = '1'
    b.append(t1)
    b.append(t2)
for i in range(0, b[-1] + 1):
    s = a[i:i + 3600]
    if s.count('1') > t:
        y = i
        break
print(y)