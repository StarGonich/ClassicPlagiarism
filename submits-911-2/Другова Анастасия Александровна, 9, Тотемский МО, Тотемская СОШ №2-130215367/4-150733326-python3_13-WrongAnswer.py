import math

def dist(p1, p2):
  return math.hypot(p1[0] - p2[0], p1[1] - p2[1])

def classify(points, i, k):
  others = [(dist(points[j], points[i]), points[j][2]) for j in range(len(points)) if j != i]
  colors = sorted(others)[:k]
  return 0 if sum(color for _, color in colors) < k // 2 else 1

def main():
  n = int(input())
  points = [tuple(map(int, input().split())) for _ in range(n)]
  results = [ ]
  for k in range(1, n, 2):
      correct = sum(classify(points, i, k) == points[i][2] for i in range(n))
      results.append(correct)
  print("\n".join(map(str, results)))

main()