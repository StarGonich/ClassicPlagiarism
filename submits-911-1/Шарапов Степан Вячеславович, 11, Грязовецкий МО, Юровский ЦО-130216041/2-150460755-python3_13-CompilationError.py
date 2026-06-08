n = int(input())

t = 1 « 29     # 2^29 = 536870912 < 10^9
divs = []

x = n
bit = 0
while x > 0:
    if x & 1:
        divs.append(1 « bit)
    bit += 1
    x »= 1

print(t)
print(*divs)