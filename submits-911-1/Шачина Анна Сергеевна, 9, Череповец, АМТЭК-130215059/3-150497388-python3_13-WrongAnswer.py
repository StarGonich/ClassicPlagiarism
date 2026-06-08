N = int(input())
T = int(input())
b = list()
c = list()
for i in range(N):
    t1, t2 = map(int, input().split())
for i in range(t1, t2):
    if t2 - t1 < N * T:
        a = (-1)
    else:
        a = (t1)
print(a)