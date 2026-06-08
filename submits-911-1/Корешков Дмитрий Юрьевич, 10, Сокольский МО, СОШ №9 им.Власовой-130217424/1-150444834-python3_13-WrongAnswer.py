def solve():
    h1 = int(input())
    m1 = int(input())
    h2 = int(input())
    m2 = int(input())
    count = 0
    ch = h1
    cm = m1
    while True:
        sh = str(ch).zfill(2)
        sm = str(cm).zfill(2)
        if sh == sm:
            count += 1
        elif sh == sm[::-1]:
            count += 1
        else:
            combined = sh + sm
            is_consecutive = True
            for i in range(3):
                if int(combined[i]) + 1 != int(combined[i+1]):
                    is_consecutive = False
                    break
            if is_consecutive:
                count += 1
        cm += 1
        if cm == 60:
            cm = 0
            ch += 1
            if ch == 24:
                ch = 0
        if ch == h2 and cm == m2:
            sh = str(ch).zfill(2)
            sm = str(cm).zfill(2)
            if sh == sm:
                count += 1
            elif sh == sm[::-1]:
                count += 1
            else:
                combined = sh + sm
                is_consecutive = True
                for i in range(3):
                    if int(combined[i]) + 1 != int(combined[i + 1]):
                        is_consecutive = False
                        break
                if is_consecutive:
                    count += 1
            break
    print(count)
solve()
