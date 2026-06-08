n = int(input())
chel_n = n // 120

mod_n = n % 120

count = 0

for i in range(4, mod_n+1):
    if (i % 4 == 0 and i % 5 != 0 and i % 6 != 0) or (i % 4 != 0 and i % 5 == 0 and i % 6 != 0) or (i % 4 != 0 and i % 5 != 0 and i % 6 == 0):
        count += 1


print(count + (chel_n * 40))