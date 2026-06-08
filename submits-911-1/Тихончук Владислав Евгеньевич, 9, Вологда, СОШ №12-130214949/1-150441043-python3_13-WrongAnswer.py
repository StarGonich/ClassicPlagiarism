import datetime

h1 = int(input())
m1 = int(input())

h2 = int(input())
m2 = int(input())
count = 0

cur_time = datetime.datetime(2025, 11, 25, h1, m1)
time = cur_time.time()
while time.strftime('%H:%M') != (str(h2) + ':' + str(m2)):
    a = cur_time.strftime('%H:%M')
    b = a.split(':')
    d1 = int(b[0][0])
    d2 = int(b[0][1])
    d3 = int(b[1][0])
    d4 = int(b[1][1])
    if b[0] == b[1]:
        count += 1
    elif b[0] == b[1][::-1]:
        count += 1
    elif d1 + 1 == d2 and d2 + 1 == d3 and d3 + 1 == d4:
        count += 1

    cur_time = cur_time + datetime.timedelta(minutes=1)
    time = cur_time.time()

print(count)