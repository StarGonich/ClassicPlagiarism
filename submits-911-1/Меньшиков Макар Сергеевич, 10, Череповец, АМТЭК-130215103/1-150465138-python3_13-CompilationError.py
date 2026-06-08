h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())

k = 0
while h1 <= h2:
    h = str(h1)
    while m1 <= m2:
        m = str(m1)
        if h1 == m1:
            k += 1
            
        elif int(h[::-1]) == m1 or int(m[::-1]) == h1:
            k += 1
        elif h1 // 10 == h1 % 10 - 1 and h1 % 10 == m1 // 10 - 1 and m1 // 10 == m1 % 10 - 1:
            k += 1
			print(1)
        m1 += 1
    h1 += 1
print(k)


