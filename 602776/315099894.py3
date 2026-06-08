numbers = []
n = int(input())
count = 0
for i in range(1, n+1):
    numbers.append(0)
for i in range(1, n+1):
    if i % 4 == 0:
        numbers[i-1] += 1
    if i % 5 == 0:
        numbers[i-1] += 1
    if i % 6 == 0:
        numbers[i-1] += 1
for i in range(1, n+1):
    if numbers[i-1] == 1:
        count += 1
print(count)