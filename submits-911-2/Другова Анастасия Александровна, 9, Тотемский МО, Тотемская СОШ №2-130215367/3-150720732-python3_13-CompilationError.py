def solve(x, y, z):
   s = 5 * z - 2 * x - y
   a, b = divmod(s, 2)
   if b != 0 or not ((min(x, y) <= a <= max(x, y)) ^ (min(x, y) <= a + s <= max(x,y):
      return [-1]                                                
   ans = sorted([a, a + s, x, x, y])                                                   
   if ans[2] == y and ans.count(x) == 2: 
     return " ".join(map(str, ans))
   return [-1]
x, y, z = map(int , input().split())
print(solve(x, y, z))