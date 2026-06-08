n = int(input())
k = int(input())
dv = set()
import math
sqrt_n = int(math.isqrt(n)) #целочисленный к корень time limit excited :(
for d in range(1, sqrt_n + 1):
    if n % d == 0:
        dv.add(d)
        dv.add(n // d)

min_lcm = None
result_p = None

for d in dv:
    m_start = (n + 1 + d - 1) // d
    p_candidate = d * m_start
    if p_candidate <= n + k:
        current_lcm = (n // d) * p_candidate
        if min_lcm is None or current_lcm < min_lcm:
            min_lcm = current_lcm
            r = p_candidate

print(r)