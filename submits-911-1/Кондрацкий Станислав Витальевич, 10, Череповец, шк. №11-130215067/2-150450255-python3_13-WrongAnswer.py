a = int(input())
s = 0
q = 1
h = ''
g = ''
for i in range(a):
    s += 1
    h += str(a - s + 1)
    if s != a:
        h += ' '
    q *= s
for l in range(len(h)):
    g += h[-(l + 1)]
print(q)
print(h)
