x = int(input())  
y = int(input())  
z = int(input())  
sum = 5 * z
list = [x, x, y, 0, sum - 2*x - y]
print(*list)
if list != sum/5 == z:
    print(-1)