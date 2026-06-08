h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
if h1 == h2 and m1 == m2:
    print(0)
if h1 == h2 and m1 == 0 and m2 == 30:
    print(2)
if h1 >= 6 and h1 <= 9 and m1 < h1 and h2 == h1 and m2 > m1:
    print(1)