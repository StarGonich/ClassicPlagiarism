n = int(input())
t = int(input())
c = 0
for i in range(n):
    t1, t2 = map(int, input().split())
    c += t2- t1
    if c > t:
        print(c)
if c <= t:
    print(-1)