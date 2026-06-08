n = int(input())

if(n == 1):
    print("1 1")
elif(n == 2):
    print("3 4 5")
else:
    s = str(n-2) + " "
    for i in range(n-1):
        s = s + "2 "
    s = s + str(n)
    print(s)
    