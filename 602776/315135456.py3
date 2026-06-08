n = int(input())
s = input()
if n == 1:
    s2 = s[:10] + s[:10]
    print(s2)
elif n == 2:
    if len(s) >= 20:
        print(s[-10:]+s[10:-10])
    else:
        print(s[len(s)//2:])