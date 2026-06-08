def is_beautiful_time(hours, minutes):
    h_str = f'{hours:02}'
    m_str = f'{minutes:02}'

    if h_str == m_str:
        return True

    if h_str == m_str[::-1]:
        return True

    all_digits = h_str + m_str
    digits = list(map(int, all_digits))
    for i in range(len(digits) - 1):
        if digits[i + 1] != digits[i] + 1:
            break
    else:
        return True

    return False


def main():

    h1 = int(input())
    m1 = int(input())
    h2 = int(input())
    m2 = int(input())

    beautiful_count = 0

    for hour in range(h1, h2 + 1):
        start_minute = m1 if hour == h1 else 0
        end_minute = m2 if hour == h2 else 59

        for minute in range(start_minute, end_minute + 1):
            if is_beautiful_time(hour, minute):
                beautiful_count += 1

    print(beautiful_count)


if __name__ == "__main__":
    main()