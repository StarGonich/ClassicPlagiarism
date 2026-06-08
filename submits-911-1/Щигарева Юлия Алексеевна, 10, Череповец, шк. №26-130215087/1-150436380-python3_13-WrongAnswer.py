h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
k = 0
if h2 - h1 >= 0 and m2 - m1 >= 0:
    if h1 == m2 - m1 or h1 <= m2 - m1:
        k += 1
if h1 == str((m2-m1)%10) + str((m2-m1)%100):
    k+=1
if h1 == h1 and m1 == m2:
    k == 0
print(k)

