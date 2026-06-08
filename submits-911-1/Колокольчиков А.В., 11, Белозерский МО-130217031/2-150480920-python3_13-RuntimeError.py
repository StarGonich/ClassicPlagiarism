ivs = int(input())
n = 1
while True:
    count_of_dividers = 0
    for i in range(n, 0, -1):
        if n % i == 0:
            count_of_dividers += 1
    if count_of_dividers == divs:
        print(n)
        break
    n += 1