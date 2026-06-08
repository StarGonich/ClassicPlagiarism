h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
count_beutifull_time = 0

for h in range(h1, h2+1):
    for m in range(m1, m2+1):
        if h == m:
            count_beutifull_time += 1
            continue
        m_t = str(m)
        h_t = str(h)
        m_t_obr = m_t[::-1]
        if h_t == m_t_obr:
            count_beutifull_time += 1

print(count_beutifull_time)
