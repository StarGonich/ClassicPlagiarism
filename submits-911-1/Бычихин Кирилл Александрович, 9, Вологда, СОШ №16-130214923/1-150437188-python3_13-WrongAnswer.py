import datetime



def perfect_time_count(h1, m1, h2, m2):
    perfect_count = 0
    if h1 == h2:
        for i in range(m1, m2):
            if i == h1:
                perfect_count += 1
            if str(i) == str(h1)[:-1]:
                perfect_count += 1
    else:
        for j in range(h1, h2):
            for i in range(j):
                print(i)
    return perfect_count


h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())

a = perfect_time_count(h1, m1, h2, m2)


print(a)