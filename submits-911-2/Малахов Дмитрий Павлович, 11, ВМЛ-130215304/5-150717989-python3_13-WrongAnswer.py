from decimal import Decimal
n = int(input())
q = list(map(int, input().split()))
k = int(input())
b = list(map(int, input().split()))
b.sort()
elems = []
now_ind = 0
for i in range(1, n + 1):
    if now_ind < len(b) and i == b[now_ind]:
        elems.append([q[i - 1], True])
        now_ind += 1
    else:
        elems.append([q[i - 1], False])
elems.sort()


ans_t = 1
tp = k
fp = n - k
tn = 0
fn = 0
if tp == 0:
    ans = Decimal(0)
else:
    ans = Decimal(2 * tp / (2 * tp + fn + fp))

for i in range(1, n):
    a = elems[i - 1][0]
    frod = elems[i - 1][1]
    if frod:
        tp -= 1
        fn += 1
    else:
        fp -= 1
        tn += 1

    if tp == 0:
        now_ans = Decimal(0)
    else:
        now_ans = Decimal(2 * tp / (2 * tp + fn + fp))
    if now_ans > ans:
        ans_t = elems[i - 1][0] + 1
        ans = now_ans
print(ans_t)
