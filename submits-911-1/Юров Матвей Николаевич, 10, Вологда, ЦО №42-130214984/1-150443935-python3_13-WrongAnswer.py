h1=int(input())
m1=int(input())
h2=int(input())
m2=int(input())
cnt=0
h,m=h1,m1
diff=(h2-h1)*60 + (m2-m1)
for i in range(diff):
    if ((h==1 and m==23) or (h==2 and m==34) or (h==3 and m==45) or (h==4 and m==56) or (h==12 and m==34) or (h==23 and m==45)):
        cnt+=1
    if h==m and h%10<6:
        cnt+=2
    elif h ==m:
        cnt+=1
        
    if m%60==0 and m!=0:
        h+=1
        m=0
    m+=1
print(cnt)
    