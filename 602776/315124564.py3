
money = 210

cycle = 0

print(1, "R")
money -= 1
x = int(input())

while x != -1 and money < 1000:
    if x == 0:
        cycle += 1

        if cycle == 3:
            cycle = 0
            print(money, "R")
            money <<= 1
            x = int(input())
            continue

    elif x == 1:
        cycle = 0

    print(1, "R")
    money -= 1
    x = int(input())