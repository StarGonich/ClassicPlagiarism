perfect = [
    6,
    28,
    496,
    8128,
    33550336,
    8589869056,
    137438691328,
    2305843008139952128
]

N = int(input())

for i in perfect:
    spisok = []
    r = int(i**0.5)
    for x in range(1, r + 1):
        if i % x == 0:
            spisok.append(x)
            y = i // x
            if y != x:
                spisok.append(y)
    spisok.remove(i)
    spisok.sort()
    if len(spisok) == N:
        print(i)
        print(str(spisok).replace(",", "").replace("[", "").replace("]", ""))
        break