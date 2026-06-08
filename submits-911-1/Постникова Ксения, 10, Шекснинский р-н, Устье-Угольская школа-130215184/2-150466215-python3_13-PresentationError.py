a = int(input())
c = 1
w = 0
for i in range( 1, a + 1):
    if a % c == 0:
        w = w + c
print (w)