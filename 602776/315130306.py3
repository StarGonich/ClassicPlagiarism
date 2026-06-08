def in_char(a: int) -> chr:
    return chr(65 + (a%26))

def in_code(c: chr) -> int:
    return ord(c) - 65

def ver_chr(code:str, a: int):
    s = 0
    for i in range(a-1, len(code), 2*a):
        s += sum(in_code(c) for c in code[i:i+a])
    return in_char(26-s)

def ver_chr_1(code:str, a: int):
    s = 0
    for i in range(a-1, len(code), 2*a):
        s += sum(in_code(c) for c in code[i:i+a])
    return in_char(s)


def code(code: str):
    if code == '':
        return ''
    new_code = list(code)
    a = 1
    while a < len(new_code):
        # print(a, new_code)
        new_code.insert(a-1, 'A')
        a <<= 1

    a = 1

    while a < len(new_code):
        new_code[a-1] = ver_chr(new_code, a)
        # print(a, new_code)
        a <<= 1

    return ''.join(new_code)


def decode(code: str):
    if code == '':
        return ''

    false_bit = []
    new_code = list(code)

    a = 1

    m = 0
    while a < len(new_code):
        m= max(in_code(ver_chr_1(new_code, a)),m)
        if ver_chr_1(new_code, a) == 'A':
            false_bit.append('0')
        else:
            false_bit.append('1')
        a <<= 1

    a = int(''.join(false_bit[::-1]), 2)
    new_code[a-1] = in_char(in_code(new_code[a-1]) - m)

    a = 1
    while a < len(new_code):
        new_code[a - 1] = ''
        a <<= 1

    return ''.join(new_code)


t = int(input())
s = input()

if t == 1:
    print(code(s))
if t == 2:
    print(decode(s))
