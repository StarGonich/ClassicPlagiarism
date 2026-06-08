def rev(m):
    s=''
    if m//10>0:
        s=str(m%10)+str(m//10)
    else: s=str(m%10)+'0'
    return s
def por(h,m):
    if int(h)//10<=0:
        h='0'+h
    if int(m)//10<=0:
        m='0'+m
    l=h+m
    for i in range(1,4):
        if int(l[i])!=1+int(l[i-1]):
            flag=False
            break
    if flag:
        return True
    else: return False
h1=int(input())
m1=int(input())
h2=int(input())
m2=int(input())
count=0
n=0
for h in range(h1,h2+1):
    n+=1
    
    if h<h2:
        if n==1:
            for m in range(m1,60):
                if h==m or str(h)==rev(m) or por(str(h),str(m)):
                    count+=1
                print(h,m,count)
        else: 
            for m in range(0,60):
                if h==m or str(h)==rev(m) or por(str(h),str(m)):
                    count+=1
                    print(h,m,count)
    else:
        if n==1:
            for m in range(m1,m2):
                if h==m or str(h)==rev(m) or por(str(h),str(m)):
                    count+=1
                    print(h,m,count)
        else:
            for m in range(m2):
                if h==m or str(h)==rev(m) or por(str(h),str(m)):
                    count+=1
                    print(h,m,count)
print(count)