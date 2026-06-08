h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
k = 0
end_time = h2 * 60 + m2
start_time = h1 * 60 + m1
for i in range(start_time, end_time + 1):
    h = i // 60
    m = i % 60
    if h < 10 and m > 9:
        s = "0" + str(h) + str(m)
    elif h < 10 and m < 10:
        s = "0" + str(h) + '0' + str(m)
    elif h > 9 and m < 10:
        s = str(h) + '0' + str(m)
    elif h > 9 and m > 9:
        s = str(h) + str(m)
    if h == m or h == (m % 10) * 10 + (m // 10):
        k += 1
    elif int(s[0]) == int(s[1]) - 1 and int(s[0]) == int(s[2]) - 2 and int(s[0]) == int(s[3]) - 3:
        k += 1
print(k)