a, b, p = list(map(int, input().split()))
c, d, q = list(map(int, input().split()))
r1, r2 = set(), set()
if (a, b) == (c, d) and p != q:
    print('Contradiction')
    exit()

if a == c and b != d and p == q or b == d and a != c and p == q:
    print('Contradiction')
    exit()

# if (a + b) / p > 200 or (c + d) / q > 200:
#     print('Contradiction')
#     exit()

opr = a * d - c * b
if opr == 0:
    print('Ambiguity')
    exit()
xo = p * d - q * b
yo = a * q - c * p



x = xo / opr
y = yo / opr


if x == 0 and a == 0 and c == 0 or y == 0 and b == 0 and d == 0:
    print('Contradiction')
    exit()

if x < 0 or y < 0:
    print('Not positive')
else:
    print('Success')
    print(x * 100, y * 100)