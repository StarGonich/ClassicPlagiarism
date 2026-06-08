h_start = int(input())
m_start = int(input())
h_end = int(input())
m_end = int(input())

beauty_count = 0

while m_start <= m_end or h_start < h_end:
    if str(f"{h_start}") == str(f"{m_start}"):
        beauty_count += 1
    elif str(f"{h_start}") == str(f"{m_start}"[::-1]) or str(f"{m_start}") == str(f"{h_start}"[::-1]):
        beauty_count += 1
    elif str(f"{h_start}"[0]) < str(f"{h_start}"[1]) < str(f"{m_start}"[0]) < str(f"{m_start}"[1]):
        beauty_count += 1
    if m_start >= 59:
        m_start = 0
        h_start += 1
        print(h_start)
    m_start += 1


print(beauty_count)