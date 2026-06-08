h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())

v = 0

for h in range(24):
    for m in range(60):
        a = h1 * 60 + m1
        b = h2 * 60 + m2
        c = h * 60 + m
        if a <= b:
            if c < a or c > b:
                continue
        else:
            if c > b and c < a:
                continue
        hh = f"{h:02d}"
        mm = f"{m:02d}"
        s = hh + mm
        if hh == mm:
            v += 1
        elif mm == hh[::-1]:
            v += 1
        elif all(int(s[i+1]) - int(s[i]) == 1 for i in range(3)):
            v += 1

print(v)