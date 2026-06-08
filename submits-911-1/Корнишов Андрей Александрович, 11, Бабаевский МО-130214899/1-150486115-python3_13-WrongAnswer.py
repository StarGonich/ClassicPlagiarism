h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
c = 0
h = h1
m = m1
while str(h)+str(m)!= str(h2)+str(m2):
    M = str(m)
    H = str(h)
    if len(M) < 2:
        M = "0" + M
    if len(H) < 2:
        H = "0" + H
    if H == M or H == M[1]+M[0] or (H[0] == str(int(H[1])-1) and H[1] == str(int(M[0])-1) and M[0] == str(int(M[1])-1)):
        c += 1
    m += 1
    if m > 59:
        h += 1
        m = 0
    if h > 23:
        h = 0
print(c)