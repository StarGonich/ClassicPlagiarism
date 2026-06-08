h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
k = 0
end_time = h2 * 60 + m2
start_time = h1 * 60 + m1
if start_time <= end_time:
    for i in range(start_time, end_time + 1):
        h = i // 60
        m = i % 60
        if h < 10:
            h = '0' + str(h)
        else:
            h = str(h)
        if m < 10:
            m = '0' + str(m)
        else:
            m = str(m)

        if h == m or h == m[::-1]:
            k += 1
        elif int(h[0]) == int(h[1]) - 1 and int(h[1]) == int(m[0]) - 1 and int(m[0]) == int(m[1]) - 1:
            k += 1
else:
    for i in range(start_time, 1440):
        h = i // 60
        m = i % 60
        if h < 10:
            h = '0' + str(h)
        else:
            h = str(h)
        if m < 10:
            m = '0' + str(m)
        else:
            m = str(m)

        if h == m or h == m[::-1]:
            k += 1
        elif int(h[0]) == int(h[1]) - 1 and int(h[1]) == int(m[0]) - 1 and int(m[0]) == int(m[1]) - 1:
            k += 1
    for i in range(0, end_time + 1):
        h = i // 60
        m = i % 60
        if h < 10:
            h = '0' + str(h)
        else:
            h = str(h)
        if m < 10:
            m = '0' + str(m)
        else:
            m = str(m)

        if h == m or h == m[::-1]:
            k += 1
        elif int(h[0]) == int(h[1]) - 1 and int(h[1]) == int(m[0]) - 1 and int(m[0]) == int(m[1]) - 1:
            k += 1
print(k)