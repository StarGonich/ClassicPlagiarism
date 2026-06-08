n = int(input())
k = n // 4
x = 4
arrNum = []
arrNumNot = []
if (n > 3):
    for i in range(1, k+1):
        frst = i*x
        if frst not in arrNum and frst <= n:
            arrNum.append(frst)
        else:
            arrNumNot.append(frst)
        if frst+i not in arrNum and frst+i <= n:
            arrNum.append(frst+i)
        else:
            arrNumNot.append(frst+i)
        if frst+2*i not in arrNum and frst+2*i <= n:
            arrNum.append(frst+2*i)
        else:
            arrNumNot.append(frst+2*i)
    for i in range(0, len(arrNumNot)):
        if arrNumNot[i] in arrNum:
            arrNum.remove(arrNumNot[i])
    print(len(arrNum))
else:
    print(0)