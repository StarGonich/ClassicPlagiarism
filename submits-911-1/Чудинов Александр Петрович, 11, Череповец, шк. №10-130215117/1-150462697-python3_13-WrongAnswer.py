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
if h2 - h1 == 1:
    for s in range(m1, 60):
         if s == h1:
            total += 1
         elif s // 10 == h1 % 10 and s % 10 == h1 //10:
            total +=1
         elif h1 // 10 + 1 == h1 % 10 and h1 % 10 + 1 == s // 10 and s// 10 + 1 == s%10:
            total+=1
    for r in range(m2+1):
         if r == h2:
            total += 1
         elif r // 10 == h2 % 10 and r % 10 == h2 //10:
            total +=1
         elif h2 // 10 + 1 == h2 % 10 and h2 % 10 + 1 == r // 10 and r // 10 + 1 == r%10:
            total+=1
else:
    for f in range(h1, h2+1):
        for i in range (60):
             if i == f:
                total += 1
             elif i // 10 == f % 10 and i % 10 == f //10:
                total +=1
             elif f // 10 + 1 == f % 10 and f % 10 + 1 == i // 10 and i // 10 + 1 == i%10:
                total+=1
  

print(total-total2)