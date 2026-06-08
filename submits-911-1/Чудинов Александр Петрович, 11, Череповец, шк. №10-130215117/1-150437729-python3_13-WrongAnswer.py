h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
total = 0
total2 = 0
if h2 - h1 == 0:
    for j in range(m1,m2):
        if j == h1:
            total += 1
        if j // 10 == h1 // 10 and j % 10 == h1 %10:
            total+=1
        if h1 // 10 + 1 == h1 % 10 and h1 % 10 + 1 == j // 10 and j // 10 + 1 == j%10:
            total+=1

print(total)
    