p1 = float(input())
p2 = float(input())
p3 = float(input())

q1 = 1 - p1
q2 = 1 - p2
q3 = 1 - p3

prob_correct = (p1 * p2 * q3 + p1 * q2 * p3 + q1 * p2 * p3 + p1 * p2 * p3)
print(f"{prob_correct:.4f}")