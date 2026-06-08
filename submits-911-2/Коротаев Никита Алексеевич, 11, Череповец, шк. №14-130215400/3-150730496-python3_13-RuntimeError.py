from itertools import product
from collections import Counter

x, y, z = int(input()), int(input()), int(input())
def solve(x, y, z):
    for combination in product(range(-10**9, 10**9), repeat=5):
        if x != sorted(combination)[2] or y != Counter(combination).most_common(1)[0][0] or z * 5 != sum(combination):
            continue
        return list(combination)
    return [-1]
print(solve(x, y, z))