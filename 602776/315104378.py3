N = int(input())
cnt = 0
def xor(a, b):
    return (not(a) and b) or (a and not(b))
for i in range(1, N+1):
    if xor(xor(i % 4 == 0, i % 5 == 0), i % 6 == 0):
        cnt += 1
print(cnt)