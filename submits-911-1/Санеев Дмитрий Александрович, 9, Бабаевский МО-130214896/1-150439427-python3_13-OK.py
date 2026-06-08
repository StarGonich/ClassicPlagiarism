h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())

def in_range(h, m, h_start, m_start, h_end, m_end):
    start = h_start * 60 + m_start
    end = h_end * 60 + m_end
    current = h * 60 + m
    if start <= end:
        return start <= current <= end
    else:
        return current >= start or current <= end

def is_beautiful(h, m):
    h_str = f"{h:02d}"
    m_str = f"{m:02d}"
    if h_str == m_str:
        return True

    if sorted(h_str) == sorted(m_str):
        if list(h_str) == list(m_str)[::-1]:
            return True

    combined = h_str + m_str
    digits = list(map(int, combined))
    for i in range(3):
        if digits[i+1] - digits[i] != 1:
            break
    else:
        return True
    return False 

count = 0
for h in range(24):
    for m in range(60):
        if in_range(h, m, h1, m1, h2, m2):
            if is_beautiful(h, m):
                count += 1

print(count)