from math import ceil

n = int(input())
t = int(input())
s = [tuple(map(int, input().split())) for _ in range(n)]
start = s[0][0]
finish = s[-1][-1]
delta = 3600
ind = 0
print(-1)
    
    