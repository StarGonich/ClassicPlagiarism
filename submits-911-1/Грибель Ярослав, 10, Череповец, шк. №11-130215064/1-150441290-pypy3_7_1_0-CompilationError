h1 = input()
m1 = input()
h2 = input()
m2 = input()
a = h1
b = m1
count = 0
n = 0
if int(h2) > int(h1):
    n = int(h2) - int(h1)
elif int(h1) > int(h2):
    n = 24 - int(h1) + int(h2)
else:
    n = 1
print(n)
for i in range(n):
    
    if a == b or a == b[::-1] or (a == "01" and b == "23") or (a == "12" and b == "34") or (a == "23" and b == "45"):
        count += 1
    while int(b) != 59:
        b = f"{"0" if int(b) < 9 else ""}{int(b) + 1}"
        if a == b or a == b[::-1] or (a == "01" and b == "23") or (a == "12" and b == "34") or (a == "23" and b == "45"):
            count += 1
        if a == h2 and b == m2:
            break
    if a == h2 and b == m2:
        break
    a = f"{"0" if int(a) < 9 else ""}{int(a) + 1}"
    b = "00"
    
print(count)