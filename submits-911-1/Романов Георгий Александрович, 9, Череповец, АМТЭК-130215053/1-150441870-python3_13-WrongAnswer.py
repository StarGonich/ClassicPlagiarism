h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
k = 0
for h in range(h1, h2 + 1):
    for m in range(m1 + 1, m2 + 1):

        if h == m:
            k += 1
        m12 = m // 10
        m22 = m % 10
        h12 = h // 10
        h22 = h % 10
        if h == m22 * 10 + m12:
            k = k + 1
        if h12 < h22 and h22 < m12 and m12 < m22:
            k = k + 1
        
        if h == m and h == m22 * 10 + m12:
            k = k - 1
print(k)