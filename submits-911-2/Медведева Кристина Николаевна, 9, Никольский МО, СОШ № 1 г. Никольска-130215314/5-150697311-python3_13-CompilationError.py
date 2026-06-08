def calculate_f1(tp, fp, fn):
    if tp + fp == 0:
        precision = 0
    else:
        precision = tp / (tp + fp)

    if tp + fn == 0:
        recall = 0
    else:
        recall = tp / (tp + fn)

    if precision + recall == 0:
        return 0
    else:
        return 2 * precision * recall / (precision + recall)

def solve():
    n = int(input())
    p_values = list(map(int, input().split()))
    k = int(input())
    fraud_indices_1_based = list(map(int, input().split()))

    # Convert fraud indices to 0-based
    fraud_indices = {idx - 1 for idx in fraud_indices_1_based}

    # Create a list of (p_value, is_fraud) tuples
    messages = []
    for i in range(n):
        is_fraud = i in fraud_indices
        messages.append((p_values[i], is_fraud))

    # Sort messages by p_value to efficiently iterate through thresholds
    messages.sort()

    # Collect all unique p_values as potential thresholds
    potential_thresholds = sorted(list(set(p_values)))

    max_f1 = -1.0
    best_t = -1

    # Iterate through all possible thresholds
    # A threshold T means messages with P >= T are considered fraud.
    # The possible thresholds are the unique P values.
    # We also need to consider thresholds that are just above the highest P value
    # to correctly classify all messages as non-fraud.

    all_possible_p_values = sorted(list(set(p_values)))
    thresholds_to_check = []
    for val in all_possible_p_values:
        thresholds_to_check.append(val)
    # Add a threshold that is greater than any P value to consider the case where no message is flagged as fraud
    if all_possible_p_values:
        thresholds_to_check.append(all_possible_p_values[-1] + 1)
    else: # Handle case where N=0, though constraints say N>=1
        thresholds_to_check.append(1)


    for t in thresholds_to_check:
        tp = 0
        fp = 0
        tn = 0
        fn = 0

        for p, is_fraud in messages:
            if p >= t:  # Algorithm predicts fraud
                if is_fraud:
                    tp += 1
                else:
                    fp += 1
            else:  # Algorithm predicts not fraud
                if is_fraud:
                    fn += 1
                else:
                    tn += 1

        current_f1 = calculate_f1(tp, fp, fn)

        if current_f1 > max_f1:
            max_f1 = current_f1
            best_t = t
        elif current_f1 == max_f1:
            # If F1 scores are equal, choose the smallest T
            if best_t == -1 or t <best_t:
                best_t = t

    # If no messages were processed (e.g., N=0, though constraints prevent this),
    # or if all F1 scores were 0, we need a default.
    # The problem asks for a natural number (positive integer).
    # If no fraud messages exist, any T will result in F1=0.
    # If all messages are fraud, any T will result in F1=0.
    # The smallest possible T is 1.
    if best_t == -1:
        print(1)
    else:
        print(best_t)

solve()

Больше: https://sinonim.org/solver#res