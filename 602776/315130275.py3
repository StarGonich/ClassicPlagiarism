money = 210

cycle = 0

st = 5

print(st, "R")
money -= st
x = int(input())

while x != -1 and money < 1000:
    if x == 0:
        cycle += 1

        if cycle == 1:
            st = 13
        elif cycle == 2:
            st = 24

        if cycle == 3:
            cycle = 0
            st = money

    elif x == 1:
        money += st * 2

        st = 5
        cycle = 0

    if money >= 1000:
        break

    print(st, "R")
    money -= st
    x = int(input())