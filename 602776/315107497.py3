a, b, p = list(map(int, input().split()))
c, d, q = list(map(int, input().split()))
r1, r2 = set(), set()
if (a, b) == (c, d) and p != q:
    print('Contradiction')
    exit()
opr = a * d - c * b
if opr == 0:
    print('Ambiguity')
    exit()
xo = p * d - q * b
yo = a * q - c * p

x = xo / opr
y = yo / opr

if x < 0 or y < 0:
    print('Not positive')
else:
    print('Success')
    print(x * 100, y * 100)