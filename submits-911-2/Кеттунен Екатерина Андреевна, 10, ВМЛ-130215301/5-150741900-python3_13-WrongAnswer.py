n = int(input())
p = [int(x) for x in input().split()]
k = int(input())
f = [int(x) for x in input().split()]
tp = 0
fp = 0
tn = 0
fn = 0
tt = []
F = 0
a = []
b = []
for t in range(n):
    for i in range(n):
        if p[i] >= t:
            a.append(p[i])
    for i in range(len(a)):
        b.append(a.index(a[i]))
    for j in range(k):
        if f[j] in b:
            tp += 1
        else:
            fn += 1
    fp = len(b) - tp
    precision=tp/(tp+fp)
    recall=tp/(tp+fn)
    if precision == 0 and recall == 0:
        F = 0
    else:
        F=2*precision*recall/(precision+recall)
    tt.append(F)
print(tt.index(max(tt))+1)