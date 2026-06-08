def solve():
  x = int(input())
  y = int(input())
  z = int(input())
  for a in range(-100, 101):
    for b in range(-100, 101):
      arr = [a, b, x, x, y]
       arr.sort()

       if arr[2] != y:
        continue

       counts = {}
       for num in arr:
         counts[num] = counts.get(num, 0) + 1

       max_count = 0
       mode = None
       for num, count in counts.items():
         if count > max_count:
           max_count = count
           mode = num

       mode_count = 0
       for num, count in counts.items():
         if count == max_count:
           mode_count += 1

       if mode != x or mode_count != 1:
         continue

       if sum(arr) / 5 != z:
         continue
       print(*arr)
       return
 print(-1)
solve()