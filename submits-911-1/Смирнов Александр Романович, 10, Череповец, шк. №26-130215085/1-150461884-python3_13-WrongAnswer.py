a = int(input())
b = int(input())
c = int(input())
d = int(input())
v = 0
f = 0

if a == b:
    v = v+1
    if b != a:
        v = v+0
if c == d:
    f = f+1
    if c != d:
        f = f+0

print(v+f)


