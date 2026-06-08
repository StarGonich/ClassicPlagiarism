def is_beautiful(h, m):
    h_str = f"{h:02d}"
    m_str = f"{m:02d}"
    
    if h_str == m_str:
        return True
    
    if h_str == m_str[1] + m_str[0]:
        return True
    
    s = h_str + m_str
    for i in range(3):
        if int(s[i+1]) != int(s[i]) + 1:
            return False
    return True

h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())

count = 0
a, b = h1, m1

while True:
    if is_beautiful(a, b):
        count += 1
    
    if a == h2 and b == m2:
        break
    
    b += 1
    if b == 60:
        b = 0
        a += 1
        if a == 24:
            a = 0

print(count)

