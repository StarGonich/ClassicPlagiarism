n = int( input())
if n ==1:
    print (1)
    print (1)
if n==2:
    print(-1)
if n ==3:
    print (6)
    print (1,2,3)
if  (n>3):
    print (2**(n-4)*12)
    a = [1,2,3,6]
    for i in range (n-4):
        a.append ( 2**i *12)
    for el in a:
        print (el, end =' ')
    