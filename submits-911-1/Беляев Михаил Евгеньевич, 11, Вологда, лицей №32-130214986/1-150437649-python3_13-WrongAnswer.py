h1,m1,h2,m2=int(input()),int(input()),int(input()),int(input())
k=0
if h1<h2 or (h1==h2 and m1>m2):
    for i in range(h1*60+m1,23*60+60):
        h=str(i//60) if i//60>9 else "0"+str(i//60)
        m=str(i%60) if i%60>9 else "0"+str(i%60)
        if h==m or (h[0]==m[1] and h[1]==m[0]) or (int(h[0])+1==int(h[1]) and int(h[1])+1==int(m[0]) and int(m[0])+1==int(m[1])):
            k+=1

    for i in range(0,h2*60+m2+1):
        h=str(i//60) if i//60>9 else "0"+str(i//60)
        m=str(i%60) if i%60>9 else "0"+str(i%60)
        if h==m or (h[0]==m[1] and h[1]==m[0]) or (int(h[0])+1==int(h[1]) and int(h[1])+1==int(m[0]) and int(m[0])+1==int(m[1])):
            k+=1
else:     
    for i in range(h1*60+m1,h2*60+m2+1):
        #i//60 - hour
        #i%60 - min
        h=str(i//60) if i//60>9 else "0"+str(i//60)
        m=str(i%60) if i%60>9 else "0"+str(i%60)
        if h==m or (h[0]==m[1] and h[1]==m[0]) or (int(h[0])+1==int(h[1]) and int(h[1])+1==int(m[0]) and int(m[0])+1==int(m[1])):
            k+=1
print(k)