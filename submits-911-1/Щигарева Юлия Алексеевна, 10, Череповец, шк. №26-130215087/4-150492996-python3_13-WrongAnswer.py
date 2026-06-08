from math import gcd

n = int(input())
k = int(input())
mlcm = 0

def nlcm(a, b):
    return a * b // gcd(a, b )


for i in range(n + 1, n+ k + 1):
    clcm = nlcm(n, i)
    if mlcm is None or clcm < mlcm:
        mlcm = clcm

print(mlcm)