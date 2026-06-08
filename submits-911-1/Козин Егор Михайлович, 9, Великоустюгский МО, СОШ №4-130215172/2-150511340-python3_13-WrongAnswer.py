z=int(input())
summa=0
deliteli=[]
tt=False
for i in range(100000):
    for n in range(z):
        inn=i+(n+1)
        summa+=inn
        deliteli.append(inn)
        
    
    for q in deliteli:
        if summa%q!=0:
            deliteli.clear()
            summa=0
            break
        else:
            tt=True
        
    if summa==sum(deliteli) and tt==True:
        break
    else:
        deliteli.clear()
        summa=0
if len(deliteli)==0:
    print(-1)
else:
    print(summa)
    print(*deliteli)