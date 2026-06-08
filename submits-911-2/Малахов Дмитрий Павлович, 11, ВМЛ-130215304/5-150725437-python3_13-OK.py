def sum(a, b):
    c = []
    for i in range(4):
        c.append(a[i] + b[i])
    return c


n = int(input())
q = list(map(int, input().split()))
k = int(input())
b = list(map(int, input().split()))
b.sort()

vals = []
now_ind = 0
for i in range(1, n + 1):
    if now_ind < len(b) and i == b[now_ind]:
        vals.append([q[i - 1], [-1, 0, 0, 1]])
        now_ind += 1
    else:
        vals.append([q[i - 1], [0, -1, 1, 0]])

vals.sort()

elems = []
now = vals[0][1]
for i in range(1, n):
    if vals[i - 1][0] == vals[i][0]:
        now = sum(now, vals[i][1])
    else:
        elems.append([vals[i - 1][0], now])
        now = vals[i][1]
elems.append([vals[n - 1][0], now])

ans_t = 1
tp = k
fp = n - k
tn = 0
fn = 0
if tp == 0:
    ans = 0
else:
    ans = 2 * tp / (2 * tp + fn + fp)

for [a, frod] in elems:
    tp += frod[0]
    fp += frod[1]
    tn += frod[2]
    fn += frod[3]

    if tp == 0:
        now_ans = 0
    else:
        now_ans = 2 * tp / (2 * tp + fn + fp)
    if now_ans > ans:
        ans_t = a + 1
        ans = now_ans

print(ans_t)
