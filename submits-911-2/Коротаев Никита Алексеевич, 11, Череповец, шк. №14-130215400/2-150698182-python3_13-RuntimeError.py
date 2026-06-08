p1, p2, p3 = int(input())
print(p1*p2*p3 + p1*p2*(1-p3) + p1*(1-p2) * p3 + (1-p1) * p2 * p3)