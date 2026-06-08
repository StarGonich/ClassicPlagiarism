n = int(input())
cnt = 0
setFour = set(range(4, n+1, 4))
setFive = set(range(5, n+1, 5))
setSix = set(range(6, n+1, 6))
cntFour = setFour - setFive - setSix
cntFive = setFive - setFour - setSix
cntSix = setSix - setFive - setFour
print(len(cntFour) + len(cntFive) + len(cntSix))