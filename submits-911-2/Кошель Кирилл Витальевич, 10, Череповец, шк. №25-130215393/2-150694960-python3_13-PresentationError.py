a = float(input())
b = float(input())
c = float(input())
print("Введите 3 числа:")
if a >= 0.5 and a <= 1:
    a = True
else:
    a = False
if b >= 0.5 and b <= 1:
    b = True
else:
    b = False
if c >= 0.5 and c <= 1:
    c= True
else:
    c = False
d = (a+b+c)/3
print("Итоговая вероятность верного диагноза:",d)