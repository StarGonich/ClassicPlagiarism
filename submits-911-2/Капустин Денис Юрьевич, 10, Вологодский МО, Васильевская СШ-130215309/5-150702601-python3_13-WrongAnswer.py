def solve():
    n = int(input())
    p_values = list(map(int, input().split()))
    k = int(input())
    sorted_messages_with_p = sorted(p_values, reverse=True)
    messages = []
    for i, p in enumerate(sorted_messages_with_p):
        is_spam = (i >= n - k)
        messages.append({'p': p, 'is_spam': is_spam})
    messages.append({'p': float('inf'), 'is_spam': False})
    messages.append({'p': 0, 'is_spam': True})
    unique_p_values = sorted(list(set([msg['p'] for msg in messages])), reverse=True)
    max_f1 = -1.0
    best_t = -1
    potential_t_values = set()
    for p in unique_p_values:
        if p != float('inf'):
            potential_t_values.add(p)
            potential_t_values.add(p + 1)
    potential_t_values.add(1)
    if sorted_messages_with_p:
        potential_t_values.add(max(sorted_messages_with_p) + 1)
    else:
        potential_t_values.add(1)
    sorted_potential_t = sorted(list(potential_t_values), reverse=True)
    total_spam_count = k
    total_not_spam_count = n - k
    current_tp = 0
    current_fp = 0
    current_fn = total_spam_count
    current_tn = 0
    message_index = 0