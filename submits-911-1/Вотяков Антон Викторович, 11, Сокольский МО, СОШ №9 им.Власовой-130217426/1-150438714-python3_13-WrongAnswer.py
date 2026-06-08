h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
h = abs(h2-h1); m =abs(h2-h1)
cnt=0
for i in range(h):
    for j in range(m):
        if i == j:
            cnt+=1 
        elif str(i) == str(j)[::-1]:
            cnt+=-1
        elif m - h == 22:
            cnt+=1
print(cnt)