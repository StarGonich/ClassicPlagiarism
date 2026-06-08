count, q = 0, ''
for i in range(2):
    hour, minute = input(), input()
    if int(hour) < 10:
        hour = f'0{hour}'
    if int(minute) < 10:
        minute = f'0{minute}'
    if hour == minute:
        z += 1
    elif hour[0] == minute[1] and hour[1] == minute[0]:
        count += 1
    elif int(hour[0]) == int(hour[1]) - 1 and int(hour[1]) == int(minute[0]) - 1 and int(minute[0]) == int(minute[1]) - 1:
        count += 1
print(count)
    
