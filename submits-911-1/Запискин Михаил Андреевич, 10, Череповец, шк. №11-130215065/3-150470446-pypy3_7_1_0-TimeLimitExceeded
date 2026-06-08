n = int(input())
t = int(input())
list1 = []
list2 = []
sum41 = 0
for _ in range(n):
    t1, t2 = map(int, input().split())
    list1.append(t1)
    list2.append(t2)
if list2[-1] > 3600:

    for i in range(list2[-1] - 3600):
        a = i + 3600
        for j in range(n):
            if list1[j] < a and list1[j] > i:
                if list2[j] < a:
                    sum41 += (list2[j] - list1[j])
                else:
                    sum41 += (a - list1[j])
            elif list2[j] < a and list2[j] > i:
                sum41 += (list2[j] - i)
        if sum41 > t:
            print(i)
            break
        else:
            sum41 = 0
    else:
        print(-1)
else:
    print(-1)