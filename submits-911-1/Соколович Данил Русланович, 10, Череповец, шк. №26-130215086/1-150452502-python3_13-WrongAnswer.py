a = int(input())
b = int(input())
c = int(input())
d = int(input())
Z = a*100+b
z = c*100+d
def is_palindrome(num):
    return str(num) == str(num)[::-1]

def is_repeating(num):
    str_num = str(num)
    return str_num == str_num[0] * len(str_num)

def is_sequential(num):
    str_num = str(num)
    return all(int(str_num[i]) + 1 == int(str_num[i + 1]) for i in range(len(str_num) - 1))
def count_special_numbers(start, end):
    count = 0
    for num in range(start, end + 1):
        if is_palindrome(num) or is_repeating(num) or is_sequential(num):
            count += 1
    return count
start = Z
end = z
result = count_special_numbers(start, end)
print(result)