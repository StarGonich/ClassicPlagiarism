z=int(input())
summa=0
deliteli=[]
for i in range(1000):
    for n in range(z):
        inn=(i+1)+n
        summa+=inn
        deliteli.append(inn)
        
    
    for q in deliteli:
        if summa%q!=0:
            deliteli.clear()
            summa=0
            break
    if summa==sum(deliteli):
        break
    else:
        deliteli.clear()
        summa=0

print(summa)
print(deliteli)