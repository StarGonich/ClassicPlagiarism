n = int(input())
a = 2
b = 2
f = 0
z = 0
x = ''
y = 0

while y == 0:
    if n == 1:
        print(1)
        print(1)
        y = 1
    else:
        if f == n:
            y = 1
            print(z)
            print(x)
        else:
            if a <= b:
                if b%a == 0:
                    a += 1
                    f += 1
                    z += a
                    c = str(a)
                    x += c
                    x += ' '
                else:
                    a += 1
            else:
                b += 1
                z = 0
                f = 0
                a = 1
                x = ''
        

