n=int(input())
m=1
col=0
while m<n:
    if m//2==0:
        col+=1
    if m//3==0:
        col+=1
    m+=1
print(m)
print(col)
    
    