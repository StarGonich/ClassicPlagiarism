n = int(input())
if n==1:
    print(-1)
elif n==2:
    print(-1)
elif n==3:
    print(6)
    print(1,2,3)
elif n == 4:
    print(30)
    print(10,2,3,15)
elif n == 5:
    print(60)
    print(10,2,3,15,30)
elif n==6:
    print(60)
    print(1,2,3,4,30,20)
elif n==7:
	print(60)
	print(1,3,2,4,15,5,30)
elif n==8:
	print(120)
	print(1,2,4,5,3,15,30,60)
elif n == 9:
	print(120)
	print(1,2,4,5,3,15,10,60,20)
elif n == 10:
	print(120)
	print(1,2,4,5,3,15,10,60,12,8)
else:
	print(120*(2**(n-10)))
	print("1 2 4 5 3 15 10 12 8 60", end=" ")
	for i in range(1, n-9):
		print(120*(2**(i-1)), end=" ")