n = int(input())

a = []

for x in range (1, 10**9):
    for y in range(1, int(x/2)):
        if x%y == 0 and y!= 1 and y != x:
            print(-1)
            break
                   
    a.append(x)
    if len(a) == n:
        print(sum(a))
        for i in a:
            print(i, end = ' ')
        break
            
