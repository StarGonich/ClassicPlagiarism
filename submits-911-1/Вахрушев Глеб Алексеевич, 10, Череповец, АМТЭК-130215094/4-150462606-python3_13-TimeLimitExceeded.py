n = int(input())
k = int(input())
min = 100000000000
def NOK(n, k):
    n1 = n
    k1 = k
    while n != k:
        if k > n:
            k = k - n
        if k < n:
            n = n - k
    NOK = n1 * k1 / n
    return NOK
pl = n + 1
pr = n + k
for i in range(pl, pr + 1):
    if NOK(n, i) < min:
        min = NOK(n, i)
        index = i
print(index)