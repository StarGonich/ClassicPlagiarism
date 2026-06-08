N = int(input())
spisok = []
for i in range(10**9):
    for c in range(i):
        if c != 0:
            if i % c == 0:
                spisok.append(c)
    if i == sum(spisok) and len(spisok) == N:
        print(i)
        print(str(spisok).replace(",", "").replace("[", "").replace("]", ""))
        break
    spisok.clear()