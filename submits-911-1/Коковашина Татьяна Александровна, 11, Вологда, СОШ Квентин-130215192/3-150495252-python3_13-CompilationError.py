Конечно! Вот упрощённая версия без комментариев и с короткими именами переменных:

```python
def solve():
    n = int(input())
    t = int(input())
    
    a = []
    for _ in range(n):
        x, y = map(int, input().split())
        a.append((x, y))
    
    a.sort()
    
    c = [0]
    for x, y in a:
        c.append(y)
    
    c = sorted(set(c))
    
    for s in c:
        e = s + 3600
        sm = 0
        for x, y in a:
            if y <= s:
                continue
            if x >= e:
                break
            sm += min(y, e) - max(x, s)
            if sm > t:
                print(s)
                return
    print(-1)

solve()
```