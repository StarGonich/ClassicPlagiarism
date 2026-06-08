def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    N = int(data[0])
    T = int(data[1])
    intervals = []

    # Чтение интервалов
    index = 2
    for _ in range(N):
        t1 = int(data[index])
        t2 = int(data[index + 1])
        index += 2
        intervals.append((t1, t2))
    
    # Объединение интервалов
    merged = []
    for interval in intervals:
        if not merged or merged[-1][1] < interval[0]:
            merged.append(list(interval))
        else:
            merged[-1][1] = max(merged[-1][1], interval[1])
    
    # Создаем массив событий для скользящего окна
    events = []
    for start, end in merged:
        events.append((start, 'start'))
        events.append((end, 'end'))
    events.sort()

    total_time = 0
    current_time = 0
    left = 0
    result_start = -1
    sum_reclama = 0
    n_events = len(events)

    # Используем два указателя для скользящего окна
    for right in range(n_events):
        time_point, typ = events[right]
        if typ == 'start':
            sum_reclama += (min(time_point, events[right+1][0]) - time_point) if right+1 < n_events and events[right+1][1]=='start' else 0
        else:
            sum_reclama -= (time_point - events[left][0]) if events[left][1]=='start' else 0
