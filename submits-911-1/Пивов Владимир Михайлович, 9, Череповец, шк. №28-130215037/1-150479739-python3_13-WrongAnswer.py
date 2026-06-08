h_start = int(input())
m_start = int(input())
h_end = int(input())
m_end = int(input())

beauty_count = 0

while m_start <= m_end or h_start < h_end:
    a = str(h_start)[0] if len(str(h_start)) == 2 else "0"
    b = str(h_start)[0] if len(str(h_start)) == 1 else str(h_start)[1]
    c = str(m_start)[0] if len(str(m_start)) == 2 else "0"
    d = str(m_start)[0] if len(str(m_start)) == 1 else str(m_start)[1]

    s_1 = a + b
    s_2 = c + d
    if str(f"{h_start}") == str(f"{m_start}"):
        beauty_count += 1
    elif str(s_1) == str(s_2[::-1]) or str(s_2) == str(s_1[::-1]):
        beauty_count += 1

    if int(a < b < c < d):
        beauty_count += 1

    if m_start >= 59:
        m_start = 0
        h_start += 1
        print(h_start)
    m_start += 1
print(beauty_count)