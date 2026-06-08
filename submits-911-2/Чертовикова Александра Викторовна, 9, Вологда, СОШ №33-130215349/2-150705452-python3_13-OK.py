def calculate_probability(p1, p2, p3):
    prob_all_positive = p1 * p2 * p3
    prob_two_and_one_negative = (p1 * p2 * (1 - p3) + 
                                 p1 * (1 - p2) * p3 + 
                                 (1 - p1) * p2 * p3)
    
 
    total_probability = prob_all_positive + prob_two_and_one_negative
    return total_probability

import sys

input = sys.stdin.read
data = input().splitlines()
p1, p2, p3 = map(float, data)
result = calculate_probability(p1, p2, p3)

print(f"{result:.12f}")
