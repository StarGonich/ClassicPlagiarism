h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())

def f(h, m):
    if h == m:
        return True
    
    h_str = str(h).zfill(2)
    m_str = str(m).zfill(2)
    if h_str[::-1] == m_str:
        return True
    
    d = h_str + m_str
    if all(int(d[i+1]) == (int(d[i]) + 1) % 10 for i in range(3)):
        sok = True
        for i in range(3):
            if int(d[i+1]) != int(d[i]) + 1:
                sok = False
                break
        if sok:
            return True
    
    return False

count = 0
while True:
    if f(h1, m1):
        count += 1
    if (h1 == h2) and (m1 == m2):
        break
    m1 += 1
    if m1 == 60:
        m1 = 0
        h1 += 1
        if h1 == 24:
            h1 = 0

print(count)
