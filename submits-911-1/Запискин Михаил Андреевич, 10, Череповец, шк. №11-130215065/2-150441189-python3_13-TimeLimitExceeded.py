n = int(input())
divisions = []
a = 1
while True:
    for i in range(1,a+1):
        if a % i == 0:
            divisions.append(i)
    while True:
        b = sum(divisions) - a
        if b in divisions:
            divisions.remove(b)
        else:
            break
    if sum(divisions) == a and len(divisions) == n:
        break
    else:
        a += 1
        divisions.clear()
    if a == 10**9:
        a = -1
        divisions = []
print(a)
if len(divisions) != 0:
    print(*divisions)