p1 = float(input())
p2 = float(input())
p3 = float(input())
prob_correct_if_sick = p1 * p2 * p3 + p1 * p2 * (1 - p3) + p1 * (1 - p2) * p3 + (1 - p1) * p2 * p3
prob_correct_if_healthy = p1 * p2 * p3 + p1 * p2 * (1 - p3) + p1 * (1 - p2) * p3 + (1 - p1) * p2 * p3
result = p1 * p2 + p1 * p3 + p2 * p3 - 2 * p1 * p2 * p3
print(f"{result:.10f}")