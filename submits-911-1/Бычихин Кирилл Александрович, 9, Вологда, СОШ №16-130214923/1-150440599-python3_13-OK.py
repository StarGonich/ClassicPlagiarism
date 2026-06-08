h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())

#в минуты
start = h1*60 + m1
end = h2*60 + m2
def time_in_range(current, start, end):
    return start <= current <= end if start <= end else  current >= start or current <= end


def is_perf_num(h, m):

    time_str = f"{h:02d}{m:02d}" # f строки тут работают вообще
    hh = f"{h:02d}"
    mm = f"{m:02d}"

    # условие 1
    if (hh == mm):
        return 1
    # условие 2
    if (mm == hh[::-1]):
        return 1
    #  условие 3
    digits = list(time_str) # цифры в список из строки с числами
    for i in range(3):
        if (int(digits[i+1]) - int(digits[i]) != 1):
            break
    else:
        return 1
    return 0

count = 0
current_time = start
while True:
    h = (current_time//60) % 24
    m = current_time%60

    if is_perf_num(h, m):
        count+=1
    if current_time == end:
        break
    current_time = (current_time+1) % (24*60)#на следующую минуту

print(count)