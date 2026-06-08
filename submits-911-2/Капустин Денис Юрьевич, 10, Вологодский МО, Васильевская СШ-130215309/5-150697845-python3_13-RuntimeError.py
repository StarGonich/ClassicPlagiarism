def f1_score(tp, fp, fn):
    p = tp / (tp + fp) if (tp + fp) > 0 else 0
    r = tp / (tp + fn) if (tp + fn) > 0 else 0
    return 2 * p * r / (p + r) if (p + r) > 0 else 0
def solve():
    n = int(input())
    messages = [float(input()) for _ in range(n)]
    is_spam = [int(input()) for _ in range(n)]
    best_threshold = 0
    best_f1 = 0
    for threshold in range(101):
        t = threshold / 100
        tp, fp, tn, fn = 0, 0, 0, 0
        for i in range(n):
            if messages[i] >= t and is_spam[i] == 1:
                tp += 1
            elif messages[i] >= t and is_spam[i] == 0:
                fp += 1
            elif messages[i] < t and is_spam[i] == 0:
                tn += 1
            elif messages[i] < t and is_spam[i] == 1:
                fn += 1
        f1 = f1_score(tp, fp, fn)
        if f1 > best_f1:
            best_f1 = f1
            best_threshold = threshold
    print(best_threshold)
solve()