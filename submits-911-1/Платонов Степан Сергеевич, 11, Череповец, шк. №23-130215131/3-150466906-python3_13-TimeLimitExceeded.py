import sys

def main():
    data = sys.stdin.read().split()
    if not data:
        print(-1)
        return
    
    N = int(data[0])
    T = int(data[1])
    
    ads = []
    idx = 2
    for _ in range(N):
        t1 = int(data[idx])
        t2 = int(data[idx + 1])
        ads.append((t1, t2))
        idx += 2
    
    # Если нет рекламных вставок
    if N == 0:
        print(-1)
        return
    
    # Максимальное время, которое нужно проверить
    max_time = ads[-1][1] + 3600
    
    # Два указателя
    i = 0  # первая вставка, пересекающая текущее окно
    j = 0  # первая вставка, начинающаяся после конца окна
    
    # Перебираем все возможные начала окон
    for start in range(0, max_time + 1):
        end = start + 3600
        
        # Сдвигаем i, пока первая вставка полностью лежит до начала окна
        while i < N and ads[i][1] <= start:
            i += 1
        
        # Сдвигаем j, пока вставка начинается до конца окна
        while j < N and ads[j][0] < end:
            j += 1
        
        # Считаем суммарную длительность рекламы в текущем окне
        total_ad_time = 0
        for k in range(i, j):
            ad_start = max(ads[k][0], start)
            ad_end = min(ads[k][1], end)
            if ad_end > ad_start:  # если есть пересечение
                total_ad_time += ad_end - ad_start
        
        if total_ad_time > T:
            print(start)
            return
    
    print(-1)

if __name__ == "__main__":
    main()