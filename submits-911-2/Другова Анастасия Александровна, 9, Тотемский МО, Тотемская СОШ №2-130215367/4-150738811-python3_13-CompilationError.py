import math

def d(p1, p2):
  return math.hypot(p1[0] - p2[0], p1[1] - p2[1])

def klssfy(pts, id, k):
  ot = sorted((d(pts[i], pts[id], pts[i][2]) 
               for i in range (len(pts)) 
               if i != id)[:k]
               return 0 
               if sum(clr == 0 for _, clr in ot) > k // 2 
               else: 1

def main():
  n = int(input())
  pts = [tuple(map(int, input().split())) for _ in range(n)]
  rslt= [sum(klssfy(pts, i, k) == pts[i][2] for i in range(n) for k in range(1, n, 2)]
     
  print("\n".join(map(str, rslt)))

main()