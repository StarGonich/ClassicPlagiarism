p1 = float(input())
p2 = float(input())
p3 = float(input())

q1 = 1 - p1
q2 = 1 - p2
q3 = 1 - p3

# Все три верны
all_correct = p1 * p2 * p3

# Ровно две верны
two_12 = p1 * p2 * q3
two_13 = p1 * q2 * p3
two_23 = q1 * p2 * p3

total_probability = all_correct + two_12 + two_13 + two_23

print(total_probability)