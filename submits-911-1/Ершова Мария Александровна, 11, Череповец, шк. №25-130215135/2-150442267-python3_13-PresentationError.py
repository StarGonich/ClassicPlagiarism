m=int(input())
ttl=0
for i in range(0, m+1):
    print(i, end='')
    for j in range(1, i+1):
        if i%j==0:
            ttl+=1
        print(ttl, end='')
    print()
    