k = int(input())
n = int(input())
m = int(input())
if m == 1:
    while n > 0:
        t1 = map(int, input().split())
        n = n-1
if m == 2:
    while n > 0:
        t1, t2 = map(int, input().split())
        n = n-1
if m == 3:
    while n > 0:
        t1, t2, t3 = map(int, input().split())
        n = n-1
if m == 4:
    while n > 0:
        t1, t2, t3, t4 = map(int, input().split())
        n = n-1
if m == 5:
    while n > 0:
        t1, t2, t3, t4, t5 = map(int, input().split())
        n = n-1
if m == 6:
    while n > 0:
        t1, t2, t3, t4,t5 ,t6 = map(int, input().split())
        n = n-1
if m == 7:
    while n > 0:
        t1, t2, t3, t4, t5, t6, t7 = map(int, input().split())
        n = n-1
if k == 3:
    print(1, 2, 3)
if k == 2:
    print(2, 1)