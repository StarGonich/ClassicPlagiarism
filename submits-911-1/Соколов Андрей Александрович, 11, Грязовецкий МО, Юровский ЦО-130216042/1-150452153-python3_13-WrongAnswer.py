def is_beautiful(h, m):
    h_str = f"{h:02}"
    m_str = f"{m:02}"

    # 1) одинаковые
    if h_str == m_str:
        return True

    # 2) зеркальные
    if h_str == m_str[::-1]:
        return True

    # 3) последовательные четыре цифры
    s = h_str + m_str
    if all(int(s[i]) == int(s[i-1]) + 1 for i in range(1, 4)):
        return True

    return False


def to_minutes(h, m):
    return h * 60 + m


# ---- Чтение ввода без ошибок ----
import sys
data = [int(x) for x in sys.stdin.read().split()]
h1, m1, h2, m2 = data


start = to_minutes(h1, m1)
end   = to_minutes(h2, m2)

count = 0

for t in range(start, end + 1):
    h = t // 60
    m = t % 60
    if is_beautiful(h, m):
        count += 1

print(count)
