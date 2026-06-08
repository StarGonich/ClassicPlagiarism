x = int(input())
y = int(input())
z = int(input())
lll = []
lll.insert(2, y)
if x > y:
    lll.insert(3, x) and lll.insert(4,x)
else:
    lll.insert(0, x) and lll.insert(1,x)
print (lll)   