result_numbers = []
for a in range(1, 50):
    for b in range(1, 50):
        for c in range(1, 50):
            for d in range(1, 50):
                for e in range(1, 50):
                    if len({a, b, c, d, e}) == 5 and a + b + c + d + e == 50:
                        result_numbers.append((a, b, c, d, e))
print("Найденные числа:")
for nums in result_numbers:
    print(nums)