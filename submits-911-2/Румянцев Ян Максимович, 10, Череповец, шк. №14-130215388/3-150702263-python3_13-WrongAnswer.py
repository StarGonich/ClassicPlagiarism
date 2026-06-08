x, y, z = int(input()), int(input()), int(input())

list_ = []
list_.append(x)
list_.append(x)
list_.append(y)

a = 0
b = 0

c = a + b
c = z - x - x - y
if x == 1 or y == 1:
    a = c - 2
    b = 2
    list_.append(a)
    list_.append(b)

    for i in list_:
        print(i)
else:
    a = c - 1
    b = 1

    list_.append(a)
    list_.append(b)

    for i in list_:
        print(i)