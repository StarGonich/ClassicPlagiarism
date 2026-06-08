h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
count = 0
if h1 == h2:
        for j in range(m1, m2 + 1):
                if h1 == j:
                        print(h1, j)
                        count = count + 1
                elif int(str(h1)) == int(str(j%10)+str(j//10)):
                        print(h1, j)
                        count = count + 1
                elif (int(str(h1)[0]) + 3) == (int(str(h1)[1]) + 2) == (int(str(j)[0]) + 1) == (int(str(j)[1])):
                        count = count + 1
else:
        for i in range(h1, h2 + 1):
                if i == h1:
                        for j in range(m1, 60):
                                if i == j:
                                        count = count + 1
                                elif i == int(str(j % 10) + str(j // 10)):
                                        count = count + 1
                                elif (int(str(i)[0]) + 3) == (int(str(i)[1]) + 2) == (int(str(j)[0]) + 1) == (int(str(j)[1])):
                                        count = count + 1
                elif i == h2:
                        for j in range(0, m2 + 1):
                                if i == j:
                                        count = count + 1
                                elif i == int(str(j % 10) + str(j // 10)):
                                        count = count + 1
                                elif (int(str(i)[0]) + 3) == (int(str(i)[1]) + 2) == (int(str(j)[0]) + 1) == (int(str(j)[1])):
                                        count = count + 1
                else:
                        for j in range(0, 60):
                                if i == j:
                                        count = count + 1
                                elif i == int(str(j % 10) + str(j // 10)):
                                        count = count + 1
                                elif (int(str(i)[0]) + 3) == (int(str(i)[1]) + 2) == (int(str(j)[0]) + 1) == (int(str(j)[1])):
                                        count = count + 1
print(count)
                


                

