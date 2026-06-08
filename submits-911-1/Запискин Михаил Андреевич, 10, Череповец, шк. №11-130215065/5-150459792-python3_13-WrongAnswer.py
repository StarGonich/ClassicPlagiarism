k = int(input())
n = int(input())
m = int(input())
sum41 = 0
tuple1 = []
for i in range(k):
    for _ in range(n):
        listik = map(int, input().split())
        tuple1.append(listik)
        sum41 += sum(listik)
    if sum41 == 0:
        if i == 0:
            well = '2 1'
        else:
            well = '1 2'
    sum41 = 0
print(well)	
