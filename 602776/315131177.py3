n = int(input())
arrNum = [*set([*set(range(4, n+1, 4))] + [*set(range(5, n+1, 5))] + [*set(range(6, n+1, 6))])]
arrNumR = list(arrNum[:])
for i in range(0, len(arrNum)):
    if (arrNum[i] % 4 == 0 and arrNum[i] % 5 == 0) or (arrNum[i] % 4 == 0 and arrNum[i] % 6 == 0) or (arrNum[i] % 5 == 0 and arrNum[i] % 6 == 0):
        arrNumR.remove(arrNum[i])
print(len(arrNumR))