k = int(input())
n = int(input())
m = int(input())
sum41 = 0
sumsum = []
tuple1 = []
for i in range(k):
    for _ in range(n):
        listik = map(int, input().split())
        tuple1.append(listik)
        sum41 += sum(listik)
    sumsum.append(sum41)
    sum41 = 0
obama = sumsum.copy()
obama.sort(reverse=True)
listikk = []
for i in obama:
    listikk.append(sumsum.index(i)+1)
print(*listikk)