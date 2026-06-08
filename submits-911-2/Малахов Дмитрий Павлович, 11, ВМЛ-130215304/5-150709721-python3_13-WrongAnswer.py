n = int(input())
a = list(map(int, input().split()))
a.sort()
k = int(input())
b = list(map(int, input().split()))
ford = [False] * n
for u in b:
    ford[u - 1] = True

ind_ans = 0
tp = k
fp = 0
tn = 0
fn = n - k
if tp == 0:
    ans = 0
else:
    ans = 2 * tp / (2 * tp + fn + fp)
now_ind = 1

for i in range(1, n):
    if ford[i - 1]:
        tp -= 1
        fp += 1
    else:
        tn += 1
        fn -= 1

    now_ans = 2 * tp / (2 * tp + fn + fp)
    if now_ans > ans:
        ind_ans = i
        ans = now_ans
    now_ind += 1
if ind_ans == 0:
    print(1)
else:
    print(a[ind_ans - 1] + 1)
