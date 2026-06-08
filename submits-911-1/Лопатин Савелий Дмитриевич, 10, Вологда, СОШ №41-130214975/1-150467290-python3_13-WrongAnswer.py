h1, m1, h2, m2 = int(input()), int(input()), int(input()), int(input())
answer = 0
for x in range (h1, h2+1):
    for y in range (0, 60):
        if y < m1:
            continue
        if x == h2 and y == m2+1:
            break
        if x == y or (x // 10 == y % 10 and x % 10 == y // 10) or (x // 10 == (x % 10 - 1) and x % 10 == (y // 10 - 1) and y // 10 == (y % 10 - 1)):
            answer += 1
print(answer - 1)