a = int(input())
count = 1
print(a * 2)
while count < (a * 2):
    if a * 2 % count == 0:
        print(count, end=' ')
    count += 1
if count == 1:
    print("-1")
