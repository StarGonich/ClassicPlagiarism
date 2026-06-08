h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
h3 = h2+1
m3 = m2+1
p = 0
if h3-h1>=2 and h2!=67:
            c = h3-h1-1
            if h1>=10 and h1<=24:
                        g1 = h1//10
                        g1=str(g1)
                        g2 = h1%10
                        g2=str(g2)
                        g3=g2+g1
                        g3=int(g3)
            for i in range (m1,60):
                        if h1==i or h1==12 and i==34 or h1==1 and i==23 or h1==2 and i==34 or h1==3 and i==45 or h1==23 and i==45:
                                    p = p+1
                        if i==g3 and g3!=h1:
                                    p = p+1
            h1 = h1+1
            c = c-1
            for i in range (c):
                        for j in range (0,60):
                                    if h1>=10  and h1<=24:
                                                g1 = h1//10
                                                g1=str(g1)
                                                g2 = h1%10
                                                g2=str(g2)
                                                g3=g2+g1
                                                g3=int(g3)
                                    if h1==i or h1==12 and i==34 or h1==1 and i==23 or h1==2 and i==34 or h1==3 and i==45 or h1==23 and i==45:
                                                            p = p+1
                                    if i==g3 and g3!=h1:
                                                            p = p+1                                    
                                    h1 = h1+1                                    
            for i in range (0,m3):
                        if h1>=10 and h1<=24:
                                                g1 = h1//10
                                                g1=str(g1)
                                                g2 = h1%10
                                                g2=str(g2)
                                                g3=g2+g1
                                                g3=int(g3)
                        if h1==i or h1==12 and i==34 or h1==1 and i==23 or h1==2 and i==34 or h1==3 and i==45 or h1==23 and i==45:
                                                            p = p+1
                        if i==g3 and g3!=h1:
                                                            p = p+1
            h2 = 67
if h2==h1 and h2!=67:
            for i in range (m1,m3):
                        if h1>=10 and h1<=24:
                                                g1 = h1//10
                                                g1=str(g1)
                                                g2 = h1%10
                                                g2=str(g2)
                                                g3=g2+g1
                                                g3=int(g3)
                        if h1==i or h1==12 and i==34 or h1==1 and i==23 or h1==2 and i==34 or h1==3 and i==45 or h1==23 and i==45:
                                                            p = p+1
                        if i==g3 and g3!=h1:
                                                            p = p+1
            h2 = 67
if h2<h1 and h2!=67:
            for i in range (m1,60):
                        if h1>=10 and h1<=24:
                                                g1 = h1//10
                                                g1=str(g1)
                                                g2 = h1%10
                                                g2=str(g2)
                                                g3=g2+g1
                                                g3=int(g3)
                        if h1==i or h1==12 and i==34 or h1==1 and i==23 or h1==2 and i==34 or h1==3 and i==45 or h1==23 and i==45:
                                                            p = p+1
                        if i==g3 and g3!=h1:
                                                            p = p+1
            h1 = h1+1
            h2 = 24+h2
            c = h2-h1
            if h1==24:
                        h1=0            
            for i in range (c):
                        for j in range (0,60):
                                    if h1>=10 and h1<=24:
                                                g1 = h1//10
                                                g1=str(g1)
                                                g2 = h1%10
                                                g2=str(g2)
                                                g3=g2+g1
                                                g3=int(g3)
                                    if h1==i or h1==12 and i==34 or h1==1 and i==23 or h1==2 and i==34 or h1==3 and i==45 or h1==23 and i==45:
                                                            p = p+1
                                    if i==g3 and g3!=h1:
                                                            p = p+1
                                    if h1==24:
                                                h1=0                                    
                                    h1 = h1+1
            for i in range (0,m3):
                        if h1>=10 and h1<=24:
                                                g1 = h1//10
                                                g1=str(g1)
                                                g2 = h1%10
                                                g2=str(g2)
                                                g3=g2+g1
                                                g3=int(g3)
                        if h1==i or h1==12 and i==34 or h1==1 and i==23 or h1==2 and i==34 or h1==3 and i==45 or h1==23 and i==45:
                                                            p = p+1
                        if i==g3 and g3!=h1:
                                                            p = p+1
            h2 = 67
print(p)