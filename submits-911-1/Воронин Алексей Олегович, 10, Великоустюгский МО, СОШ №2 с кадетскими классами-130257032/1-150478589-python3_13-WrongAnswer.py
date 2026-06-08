h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
x = 0
y = 0
sh1 = h1
sm1 = m1
if h1 == h2 and m1 == m2:
    if h1 == m1 or (h1//10 == m1%10 and h1%10 == m1//10) or (h1%10 == h1//10 + 1 and m1//10 == h1%10 + 1 and m1%10 == m1//10 + 1):
        x += 1
else:
    if h1 == m1 or (h1//10 == m1%10 and h1%10 == m1//10) or (h1%10 == h1//10 + 1 and m1//10 == h1%10 + 1 and m1%10 == m1//10 + 1):
        x += 1
    if h2 == m2 or (h2//10 == m2%10 and h2%10 == m2//10) or (h2%10 == h2//10 + 1 and m2//10 == h2%10 + 1 and m2%10 == m2//10 + 1):
        x += 1





while y == 0:
    if h1 == h2 and m1 == m2:
        y = 1
    else:
        
        if m1 != 60:
            m1 += 1
            if h1 == m1 or (h1//10 == m1%10 and h1%10 == m1//10) or (h1%10 == h1//10 + 1 and m1//10 == h1%10 + 1 and m1%10 == m1//10 + 1):
                x += 1
        else:
            m1 = 0
            h1 += 1
        if h1 == 24:
            h1 = 0
else:
    if sh1 == sm1 or h2 == m2:
        print(x - 1)
    else:
        print(x)
