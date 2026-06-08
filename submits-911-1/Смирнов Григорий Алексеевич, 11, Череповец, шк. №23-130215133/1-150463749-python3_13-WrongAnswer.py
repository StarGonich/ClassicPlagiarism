def check_values(h, m):
    b_nums = [123, 234, 345, 456, 1234, 2345, 3456, 110, 220, 330,
        440, 550, 1001, 1111, 1221, 1331, 1441, 1551, 2002, 2112, 2222,
        2332, 101, 202, 303, 404, 505, 606, 707, 808, 909, 1010,
        1212, 1313, 1414, 1515, 1616, 1717, 1818, 1919, 2020, 2121,
        2323, 0
    ]
    
    k = 0
    step = 1
    if h > m :
        step = -1

    i = h
    while i <= m+1:
        if i % 100 > 59:
            i += 39

        if i // 100 > 23 and h > m:
            i = 0

        if i == h-1 or i == m+1:
            return k

        if i in b_nums:
            k += 1
        
        i += 1

    return k


def main():
    counter = 0
    h1 = input()
    m1 = input()
    h2 = input()
    m2 = input()
    if len(m1) == 1:
        m1 += "0"
        m1 = m1[::-1]

    if len(m2) == 1:
        m2 += "0"
        m2 = m2[::-1]
        
    first = int(h1+m1)
    second = int(h2+m2)
    return check_values(first, second)
    

if __name__ == "__main__":
    answer = main()
    print(answer)
