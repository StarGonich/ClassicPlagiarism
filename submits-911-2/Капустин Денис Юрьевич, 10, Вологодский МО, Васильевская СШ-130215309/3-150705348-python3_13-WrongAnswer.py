def solve():
    x = int(input())
    y = int(input())
    z = int(input())
    sum_5z = 5 * z
    if x == y:
        num1 = y - 1
        num2 = y
        num3 = y
        num4 = y + 1
        num5 = sum_5z - 4 * y
        if (5 * y + 1 < sum_5z) and \
           (5 * y - 1 != sum_5z) and \
           (5 * y + 1 != sum_5z) and \
           (num4 < num5) and \
           (abs(num1) <= 10**9 and abs(num2) <= 10**9 and abs(num3) <= 10**9 and abs(num4) <= 10**9 and abs(num5) <= 10**9):
            print(num1, num2, num3, num4, num5)
            return
    elif x < y:
        num1 = x
        num2 = x
        num3 = y
        num4 = y + 1
        num5 = sum_5z - 2 * y - 2 * x - 1
        if (3 * y + 2 * x + 2 < sum_5z) and \
           (5 * z - 2 * y - 1 != 3 * x) and \
           (5 * z - 3 * y - 1 != 2 * x) and \
           (num4 < num5) and \
           (abs(num1) <= 10**9 and abs(num2) <= 10**9 and abs(num3) <= 10**9 and abs(num4) <= 10**9 and abs(num5) <= 10**9):
            print(num1, num2, num3, num4, num5)
            return
    elif x > y:
        num1 = sum_5z - 2 * y - 2 * x + 1
        num2 = y - 1
        num3 = y
        num4 = x
        num5 = x
        if (5 * z + 2 < 3 * y + 2 * x) and \
           (5 * z - 2 * y + 1 != 3 * x) and \
           (5 * z + 1 != 3 * y + 2 * x) and \
           (num1 < num2) and \
           (abs(num1) <= 10**9 and abs(num2) <= 10**9 and abs(num3) <= 10**9 and abs(num4) <= 10**9 and abs(num5) <= 10**9):
            print(num1, num2, num3, num4, num5)
            return
    print("-1")
solve()