h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())

cnt = 0

for i in range(h1, h2 + 1):    
    if i != h2 and i != h1:
        for j in range(0, 60):
            if i == j:
                cnt += 1
            elif i == ((j % 10) * 10 + j // 10):
                cnt += 1
            elif i == (j - 22) or (j//10) - (i%10) == 1:
                cnt += 1    
    elif i == h1 and h1!=h2:
        for j in range(m1, 60):
            if i == j:
                cnt += 1
            elif i == ((j % 10) * 10 + j // 10):
                cnt += 1
            elif i == (j - 22) or (j//10) - (i%10) == 1:
                cnt += 1
    elif i == h2 and h1 != h2:
        for j in range(0, m2 + 1):
            if i == j:
                cnt += 1
            elif i == ((j % 10) * 10 + j // 10):
                cnt += 1
            elif i == (j - 22) or (j//10) - (i%10) == 1:
                cnt += 1
    elif h1 == h2:
        for j in range(m1, m2 + 1):
            if i == j:
                cnt += 1
            elif i == ((j % 10) * 10 + j // 10):
                cnt += 1
            elif i == (j - 22) or (j//10) - (i%10) == 1:
                cnt += 1
            



print(cnt)