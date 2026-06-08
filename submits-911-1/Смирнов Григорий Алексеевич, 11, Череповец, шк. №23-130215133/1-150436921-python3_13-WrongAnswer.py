def check_values(h, m):
    if h == m:
        return 1

    if h == m[::-1]:
        return 1

    if (h=="01" and m=="23") or (h=="12" and m =="34"):
        return 1

    return 0


def main():
    counter = 0
    h1 = input()
    m1 = input()
    h2 = input()
    m2 = input()
    counter += check_values(h1, m1)
    counter += check_values(h2, m2)
    return counter
    

if __name__ == "__main__":
    answer = main()
    print(answer)
