n = int(input())
p = [0]*n
x = list(map(int, input().split()))
d = list(map(int, input().split()))
k = int(input()) - 1
r = 1
stack = [k]
a = []

while len(stack) > 0:
    for m in stack:
        a.append(m)
        for i in range(n):
            if d[m] >= abs(x[m] - x[i]) and (i not in a):
                stack.append(i)
                r += 1
        stack.remove(m)
print(r)