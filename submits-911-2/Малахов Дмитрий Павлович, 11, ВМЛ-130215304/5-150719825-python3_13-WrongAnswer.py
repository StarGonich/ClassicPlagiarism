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

ind_ans = 0
tp = k
fp = n - k
tn = 0
fn = 0
if tp == 0:
    ans = 0
else:
    ans = 2 * tp / (2 * tp + fn + fp)
now_ind = 1

for i in range(1, n):
    if elems[i - 1][1]:
        tp -= 1
        fn += 1
    else:
        fp -= 1
        tn += 1

    now_ans = 2 * tp / (2 * tp + fn + fp)
    if now_ans > ans:
        ind_ans = i
        ans = now_ans
    now_ind += 1
if ind_ans == 0:
    print(1)
else:
    print(elems[ind_ans - 1][0] + 1)
