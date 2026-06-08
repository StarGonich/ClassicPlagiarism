n = int(input())
p = [int(x) for x in input().split()]
k = int(input())
f = [int(x) for x in input().split()]
tp = 0
fp = 0
tn = 0
fn = 0
F = 0
a = []
b = []
tt = []
for t in range(max(p)+1):
    for i in range(n):
        if p[i] >= t:
            a.append(p[i])
    for i in range(len(f)):
        if p[f[i]] in a:
            tp += 1
        else:
            fp += 1
    for i in range(n):
        if p[i] < t:
            b.append(p[i])
    for i in range(len(f)):
        if p[f[i]-1] in b:
            fn += 1
        else:
            tn += 1
    precision=tp/(tp+fp)
    recall=tp/(tp+fn)
    if precision == 0 and recall == 0:
        F = 0
    else:
        F=2*precision*recall/(precision+recall)
    tt.append(F)
print(tt)
print(tt.index(max(tt))+1)