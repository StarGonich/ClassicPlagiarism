n = int(input())
if n * (n + 1) // 2 > 10**9:
    print(-1)
else:
    m = n * (n + 1) // 2 
    print(m)
    print(' '.join(map(str, range(1, n + 1)))) #ну что еще