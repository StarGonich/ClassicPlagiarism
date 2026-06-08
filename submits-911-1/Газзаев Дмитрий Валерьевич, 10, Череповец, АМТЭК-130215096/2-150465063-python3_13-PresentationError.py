n = int(input())
m = 1
s = 0
k = 0
a = []
while k != 1:
            for i in range(1, m):
                        if len(a) != n:
                                    if m % i == 0 and i not in a:
                                                s += i
                                                a = a + [i]
            if m != s:
                        m += 1
                        a = []
                        s = 0
            else:
                        print(m)
                        print(*a)
                        k += 1
if k == 0:
            print('-1')