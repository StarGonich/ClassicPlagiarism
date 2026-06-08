h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
k = 0
if h1 == h2 and m1 == m2:
    print(0)
if h1 == h2 and m2-m1>h1:
    print(2)
if h1 - h2 == 1 and m2-m1>h1:
    print(4)
