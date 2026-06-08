p1 = float(input())
p2 = float(input())
p3 = float(input())

probability = (p1 * p2 * p3 +
               p1 * p2 * (1 - p3) +
               p1 * (1 - p2) * p3 +
               (1 - p1) * p2 * p3)

print(probability)