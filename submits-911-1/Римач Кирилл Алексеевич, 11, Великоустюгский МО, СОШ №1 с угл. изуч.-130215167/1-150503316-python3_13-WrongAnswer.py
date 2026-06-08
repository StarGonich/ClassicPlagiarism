def rev(m):
    s=''
    if m//10>0:
        s=str(m%10)+str(m//10)
    else: s=str(m%10)+'0'
    return s
def por(h,m):
    if (h==1 and m==23) or (h==12 and m==34) or (h==23 and m==45): return True
    else: return False
h1=int(input())
m1=int(input())
h2=int(input())
m2=int(input())
count=0
n=0
for h in range(h1,h2+1):
    n+=1
    if h<10:hstr='0'+str(h)
    else: hstr=str(h)
    if h<h2:
        if n==1:
            for m in range(m1,60):
                if h==m or hstr==rev(m) or por(h,m):
                    count+=1
        else: 
            for m in range(0,60):
                if h==m or hstr==rev(m) or por(h,m):
                    count+=1
    else:
        if n==1:
            for m in range(m1,m2+1):
                if h==m or hstr==rev(m) or por(h,m):
                    count+=1
        else:
            for m in range(m2+1):
                if h==m or hstr==rev(m) or por(h,m):
                    count+=1
print(count)