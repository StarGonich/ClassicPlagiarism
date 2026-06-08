a = int(input())
b = int(input())
c = int(input())
d = int(input())
ans = 0

r = (c-a)*60+(d-b)
for i in range(0, r):
    if b == 60:
        a = a+1
        b = 0
    a = str(a)
    b = str(b)
    if a != '0' and a != '1' and a != '2' and a != '3' and a != '4' and a != '5' and a != '6' and a != '7' and a != '8' and a != '9' and b != '0' and b != '1' and b != '2' and b != '3' and b != '4' and b != '5' and b != '6' and b != '7' and b != '8' and b != '9':
        if a == b:
            ans = ans+1
            print(a, ':', b)
        elif a[0] == b[1] and a[1] == b[0]:
            ans = ans+1
            print(a, ':', b)
        elif int(a[1]) == int(a[0])+1 and int(b[0]) == int(a[1])+1 and int(b[1]) == int(b[0])+1:
            ans = ans+1
            print(a, ':', b)
    else:
        if a == b:
            ans = ans+1
            print(a, ':', b)
        elif int(a) > 9:
            if a[0] == b[0] and a[1] == '0':
                ans = ans+1
                print(a, ':', b)
            elif a == '0' and b == '12':
                ans = ans+1
                print(a, ':', b)
        elif int(b) > 9:
            if a[0] == b[1] and b[0] == '0':
                ans = ans+1
                print(a, ':', b)
            elif a == '0' and b == '12':
                ans = ans+1
                print(a, ':', b)
        else:
            if a == '0' and b == '1':
                ans = ans+1
                print(a, ':', b)
    a = int(a)
    b = int(b)
    b = b+1
print(ans)