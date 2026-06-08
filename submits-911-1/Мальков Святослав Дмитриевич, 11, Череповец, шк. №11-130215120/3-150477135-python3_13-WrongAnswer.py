n = int(input())
T = int(input())
e = []
e1 = []
t1, t2 = map(int, input().split())
e.append(t1)
e.append(t2 - t1)
for i in range(n - 1):
    t1, t2 = map(int, input().split())
    e.append(t1 - sum(e))
    e.append(t2 - t1)
mad = []
submad = []
for i in range(1, len(e)):
    if i % 2 != 0:
        mad = mad + [1] * e[i]
    else:
        mad = mad + [0] * e[i]
for i in range(0, len(mad) - 3600):
    if mad[i:i + 3600].count(1) > T:
        submad.append(i)
if submad == []:
    print('-1')
else:
    print(submad[0] + 1)