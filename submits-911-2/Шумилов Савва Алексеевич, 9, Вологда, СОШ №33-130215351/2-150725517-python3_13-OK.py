def a(p1, p2, p3):
    result = p1 * p2 * (1 - p3) + p1 * (1 - p2) * p3 + (1 - p1) * p2 * p3 + p1 * p2 * p3
    return round(result, 4) 
p1 = float(input())
p2 = float(input())
p3 = float(input())
konec = a(p1, p2, p3)
print(konec)