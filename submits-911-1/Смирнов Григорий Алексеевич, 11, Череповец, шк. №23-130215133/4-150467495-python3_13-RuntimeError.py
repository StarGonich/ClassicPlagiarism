def nok(n, p):
    array = [a for a in range(max(n, p), max(n, p)*2+1) if a % n == 0 and a % p == 0]
    if array == []:
        return float('inf')
    for i in array:
        # print(f'i: {i}')
        if i % n + i % p == 0:
            return i

    return float('inf')


def main():
    n = int(input())
    k = int(input())
    min_nok = float('inf')
    p_m = float('inf')
    for p in range(n+1, n+k+1):
        # print(f"n: {n}, k: {k}, n+k+1: {n+k+1} p: {p}")
        num = nok(n, p)
        # print(f"num: {num}")
        p_m = p if num < min_nok else p_m
        min_nok = num if num < min_nok else min_nok

    return p_m
    
    

if __name__ == "__main__":
    answer = main()
    print(answer)

if __name__ == "__main__":
    answer = main()
    print(answer)
