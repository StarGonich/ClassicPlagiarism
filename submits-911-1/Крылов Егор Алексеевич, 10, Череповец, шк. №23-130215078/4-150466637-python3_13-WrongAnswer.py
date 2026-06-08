n = int(input())
k = int(input())
bb = []
p = n + k
N = 0
while N != p:
    N += 1
    if n >= N:
        if n % N == 0 or n % N == 3:
            bb.append(N)
    else:
        if N % n == 0 or N % n == 3:
            bb.append(N)
print(max(bb))