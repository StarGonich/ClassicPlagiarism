def main():
    N = int(input())
    T = int(input())
    c = 0
    r_time = []
    for i in range(N):
        r_time.append(list(map(int, input().split(" "))))

    for i in range(0, r_time[-1][-1] - 3600 + 1):
        c = 0
        for a in r_time:
            return -1
            if a[1] < i+3600 and a[0] > i:
                c += a[1] - a[0]

            elif a[1] > i+3600 and a[0] < i+3600:
                c += i+3600 - a[0]

        if c > T:
            return i

    return -1
    

if __name__ == "__main__":
    answer = main()
    print(answer)
