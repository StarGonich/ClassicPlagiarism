p1 = int(input())
p2 = int(input())
p3 = int(input())
if (p1 and p2 and p3 == 0.5) and (p1 and p2 and p3 == 1) and (p1 and p2 and p3 < 1) and (p1 and p2 and p3 < 1):
    rez = (p1+p2+p3)/3
    print (rez)
else:
    print ("неверно заданная информация")