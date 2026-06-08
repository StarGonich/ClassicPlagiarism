n = int(input())

perfect = [6, 28, 496, 8128, 33550336]

def get_divs(x):
    d = []
    i = 1
    while i * i <= x:
        if x % i == 0:
            if i < x: d.append(i)
            j = x // i
            if j != i and j < x: d.append(j)
        i += 1
    return sorted(d)

for m in perfect:
    d = get_divs(m)
    if len(d) < n: 
        continue

    # итеративный поиск набора ровно из n элементов с суммой m
    stack = [(0, 0, 0, [])]  # (i, taken, sum, list)
    while stack:
        i, k, s, lst = stack.pop()
        if k == n:
            if s == m:
                print(m)
                print(*lst)
                exit()
            continue
        if i == len(d) or s > m:
            continue
        
        # взять
        if s + d[i] <= m:
            stack.append((i+1, k+1, s+d[i], lst+[d[i]]))
        # не брать
        stack.append((i+1, k, s, lst))

print(-1)
