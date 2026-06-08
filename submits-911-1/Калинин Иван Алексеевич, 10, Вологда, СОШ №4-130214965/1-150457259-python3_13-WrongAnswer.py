def beat(h, m):
    if h==m:
        return True
    if (h %10 == m//10) and (h//10 == m%10):
        return True
    if h<24 and m<60:
        if h//10-h%10==-1 and h%10-m//10==-1 and m//10-m%10==-1:
            return True
    return False
def cou(h1, m1, h2, m2):
    c = 0
    st = h1*60+m1
    end = h2*60+m2
    for i in range(st, end+1):
        h = i//60
        m = i%60
        if beat(h,m):
            c+=1
    return(c)
h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
ans = cou(h1, m1, h2, m2)
print(ans)