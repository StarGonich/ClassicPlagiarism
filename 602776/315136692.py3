n = int(input())
l = list(map(int, input().split()))
 
positions = []
 
for i in range(1, len(l)):
    if (l[i-1] + 1 != l[i]):
        positions.append(i)
 
if(len(positions) == 1):
    print(1, positions[0])
    print(positions[0]+1, n - positions[0])
elif(len(positions) == 2):
    pos1 = 0
    pos2 = 0
    len1 = 0
    len2 = 0
    if(l[0] == 1):
        pos1 = positions[0] + 1
        pos2 = positions[1] + 1
        len1 = pos2 - pos1
        len2 = n - pos2 + 1
    elif(l[len(l)-1] == n):
        pos1 = 1
        pos2 = positions[0] + 1
        len1 = pos2 - pos1
        len2 = positions[1] - positions[0]
    else:
        pos1 = 1
        pos2 = positions[1] + 1
        len1 = positions[0]
        len2 = n - positions[1]
    print(pos1, len1)
    print(pos2, len2)
elif(len(positions) == 3):
    pos1 = positions[0] + 1
    pos2 = positions[1] + 1
    len1 = pos2 - pos1
    len2 = positions[2] - positions[1]
    print(pos1, len1)
    print(pos2, len2)
elif(len(positions) == 4):
    pos1 = positions[0] + 1
    pos2 = positions[2] + 1
    len1 = positions[1] - positions[0]
    len2 = positions[3] - positions[2]
    print(pos1, len1)
    print(pos2, len2)
else:
    print(-1)