h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())

start = h1 * 60 + m1
end = h2 * 60 + m2
count = 0
t = start

while t <= end:
    h = t // 60
    m = t % 60

    s = ""
    if h < 10:
        s += "0"
    s += str(h)
    if m < 10:
        s += "0"
    s += str(m)

    cond1 = (h == m)

    cond2 = (s[0] == s[3] and s[1] == s[2])

    d0 = int(s[0])
    d1 = int(s[1])
    d2 = int(s[2])
    d3 = int(s[3])
    cond3 = (d1 == d0 + 1 and d2 == d1 + 1 and d3 == d2 + 1)

    if cond1 or cond2 or cond3:
        count += 1

    t += 1

print(count)
