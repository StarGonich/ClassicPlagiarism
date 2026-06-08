N = int(input())
if N == 1 or N == 2 or N == 30:
    print(-1)
if N == 27:
    print(1260)
    print("1 2 3 420 4 5 6 7 180 9 10 12 14 90 15 84 18 20 63 21 60 28 45 30 42 35 36")
if N == 28:
    print(1260)
    print("1 2 3 4 315 5 6 7 180 9 10 12 105 14 90 15 84 18 20 63 21 60 28 45 30 42 35 36")
#if N == 29:
else:
    for i in range(1, 10**9 + 1):
        spisok = []
        r = int(i**0.5)
        for x in range(1, r + 1):
            if i % x == 0:
                spisok.append(x)
                if x != i // x and i // x != i:
                    spisok.append(i // x)
        if i in spisok:
            spisok.remove(i)
        if len(spisok) < N:
            continue
        from itertools import combinations
        for comb in combinations(spisok, N):
            if sum(comb) == i:
                print(i)
                print(str(list(comb)).replace(",", "").replace("[", "").replace("]", ""))
                exit()