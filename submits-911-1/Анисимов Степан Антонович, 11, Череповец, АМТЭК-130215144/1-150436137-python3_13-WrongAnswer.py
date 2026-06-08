a=int(input())
b=int(input())
c=int(input())
d=int(input())
k=0
if a-c>=0:
    for i in range(a-c):
        if b-d>=0:
            for j in range(b-d):
                if a+i==b+j or str(a+i)==str(b+j)[1]+str(b+j)[0] or (int(str(a+i)[0])+1 == int(str(a+i)[1]) and int(str(a+i)[1])+1 == int(str(b+j)[0]) and int(str(b+j)[0])+1 == int(str(b+j)[1])):
                    k+=1
        else:
            for j in range(d-b):
                if a+i==b+j or str(a+i)==str(b+j)[1]+str(b+j)[0] or (int(str(a+i)[0])+1 == int(str(a+i)[1]) and int(str(a+i)[1])+1 == int(str(b+j)[0]) and int(str(b+j)[0])+1 == int(str(b+j)[1])):
                    k+=1            
else:
    for i in range(c-a):
        if b-d>=0:
            for j in range(b-d):
                if a+i==b+j or str(a+i)==str(b+j)[1]+str(b+j)[0] or (int(str(a+i)[0])+1 == int(str(a+i)[1]) and int(str(a+i)[1])+1 == int(str(b+j)[0]) and int(str(b+j)[0])+1 == int(str(b+j)[1])):
                    k+=1
        else:
            for j in range(d-b):
                if a+i==b+j or str(a+i)==str(b+j)[1]+str(b+j)[0] or (int(str(a+i)[0])+1 == int(str(a+i)[1]) and int(str(a+i)[1])+1 == int(str(b+j)[0]) and int(str(b+j)[0])+1 == int(str(b+j)[1])):
                    k+=1    
print(k)