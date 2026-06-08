a=int(input())
b=int(input())
c=int(input())
d=int(input())
k=0
if a==c:
    for i in range(b,d+1):
        if a==i:
            k+=1
        j=list(str(i))
        m=list(str(a))
        j1=['0']+j
        m1=['0']+m
        if a<10:   
            if i<10:
                j1.reverse()
                if m1==j1:
                    k+=1
                j1.reverse()
                if int(m1[1])-int(m1[0])==1 and int(j1[0])-int(m1[1])==1 and int(j1[1])-int(j1[0])==1:
                    k+=1
            if i>=10:
                j.reverse()
                if m1==j:
                    k+=1
                j.reverse()
                if int(m1[1])-int(m1[0])==1 and int(j[0])-int(m1[1])==1 and int(j[1])-int(j[0])==1:
                    k+=1
        if a>=10:   
            if i<10:
                j1.reverse()
                if m==j1:
                    k+=1
                j1.reverse()
                if int(m[1])-int(m[0])==1 and int(j1[0])-int(m[1])==1 and int(j1[1])-int(j1[0])==1:
                    k+=1
            if i>=10:
                j.reverse()
                if m==j:
                    k+=1
                j.reverse()
                if int(m[1])-int(m[0])==1 and int(j[0])-int(m[1])==1 and int(j[1])-int(j[0])==1:
                    k+=1
if a<c:
    for i in range(b,60):
        if a==i:
            k+=1
        j=list(str(i))
        m=list(str(a))
        j1=['0']+j
        m1=['0']+m
        if a<10:   
            if i<10:
                j1.reverse()
                if m1==j1:
                    k+=1
                j1.reverse()
                if int(m1[1])-int(m1[0])==1 and int(j1[0])-int(m1[1])==1 and int(j1[1])-int(j1[0])==1:
                    k+=1
            if i>=10:
                j.reverse()
                if m1==j:
                    k+=1
                j.reverse()
                if int(m1[1])-int(m1[0])==1 and int(j[0])-int(m1[1])==1 and int(j[1])-int(j[0])==1:
                    k+=1
        if a>=10:   
            if i<10:
                j1.reverse()
                if m==j1:
                    k+=1
                j1.reverse()
                if int(m[1])-int(m[0])==1 and int(j1[0])-int(m[1])==1 and int(j1[1])-int(j1[0])==1:
                    k+=1
            if i>=10:
                j.reverse()
                if m==j:
                    k+=1
                j.reverse()
                if int(m[1])-int(m[0])==1 and int(j[0])-int(m[1])==1 and int(j[1])-int(j[0])==1:
                    k+=1
    a+=1
    if a<c:
        while a<c:
            for i in range(0,60):
                if a==i:
                    k+=1
                j=list(str(i))
                m=list(str(a))
                j1=['0']+j
                m1=['0']+m
                if a<10:   
                    if i<10:
                        j1.reverse()
                        if m1==j1:
                            k+=1
                        j1.reverse()
                        if int(m1[1])-int(m1[0])==1 and int(j1[0])-int(m1[1])==1 and int(j1[1])-int(j1[0])==1:
                            k+=1
                    if i>=10:
                        j.reverse()
                        if m1==j:
                            k+=1
                        j.reverse()
                        if int(m1[1])-int(m1[0])==1 and int(j[0])-int(m1[1])==1 and int(j[1])-int(j[0])==1:
                            k+=1
                if a>=10:   
                    if i<10:
                        j1.reverse()
                        if m==j1:
                            k+=1
                        j1.reverse()
                        if int(m[1])-int(m[0])==1 and int(j1[0])-int(m[1])==1 and int(j1[1])-int(j1[0])==1:
                            k+=1
                    if i>=10:
                        j.reverse()
                        if m==j:
                            k+=1
                        j.reverse()
                        if int(m[1])-int(m[0])==1 and int(j[0])-int(m[1])==1 and int(j[1])-int(j[0])==1:
                            k+=1
            a+=1
        for i in range(0,d+1):
            if a==i:
                k+=1
            j=list(str(i))
            m=list(str(a))
            j1=['0']+j
            m1=['0']+m
            if a<10:   
                if i<10:
                    j1.reverse()
                    if m1==j1:
                        k+=1
                    j1.reverse()
                    if int(m1[1])-int(m1[0])==1 and int(j1[0])-int(m1[1])==1 and int(j1[1])-int(j1[0])==1:
                        k+=1
                if i>=10:
                    j.reverse()
                    if m1==j:
                        k+=1
                    j.reverse()
                    if int(m1[1])-int(m1[0])==1 and int(j[0])-int(m1[1])==1 and int(j[1])-int(j[0])==1:
                        k+=1
            if a>=10:   
                if i<10:
                    j1.reverse()
                    if m==j1:
                        k+=1
                    j1.reverse()
                    if int(m[1])-int(m[0])==1 and int(j1[0])-int(m[1])==1 and int(j1[1])-int(j1[0])==1:
                        k+=1
                if i>=10:
                    j.reverse()
                    if m==j:
                        k+=1
                    j.reverse()
                    if int(m[1])-int(m[0])==1 and int(j[0])-int(m[1])==1 and int(j[1])-int(j[0])==1:
                        k+=1
        
print(k)
    
