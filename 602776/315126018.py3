import sys
s = 209
lose = 0
rnd = 0
p = 1
print(1, 'R')
sys.stdout.flush()
while True:
    ans = int(input())
    rnd += 1
    if ans == 0:
        lose += 1
    if ans == 1:
        s += p * 2
        lose = 0
    if ans == -1 or s >= 1000:
        break

    if lose == 3:
        lose = 0
        p = s
        s -= p
        print(p, 'R')
        sys.stdout.flush()
    elif rnd == 2:
        rnd = -1
        print(33, 'R')
        sys.stdout.flush()
        s -= 33
        p = 33
    else:
        print(1, 'R')
        sys.stdout.flush()
        p = 1
        s -= 1
        
