def hash(curr_s):
    ans = 1
    ans1 = 0
    mod = 10 ** 9 + 7
    for el in curr_s:
        ans = (ans * ord(el) * (mod + 10)) % (10 ** 9 - 7)
    for el in curr_s:
        ans1 = (ans + ord(el) * (mod + 10)) % (10 ** 9 - 7)

    return to_26(ans + ans1)

def dehash(curr_s):
    return to_26(int(from_26(curr_s), 16))

def to_26(num):
    ans = hex(num)[2:]
    new_ans = []
    for el in ans:
        value = 0
        if el.isalpha():
            value = ord(el) - ord('a') + ord("A")
        else:
            value = int(el) + ord('F') + 1
        new_ans.append(chr(value))
    return "".join(new_ans).zfill(10).replace("0", "G")

def from_26(num):
    new_ans = []
    for el in num:
        value = 0
        if ord('A') <= ord(el) <= ord('F'):
            value = chr(ord(el) - ord('A') + ord("a"))
        else:
            value = str(ord(el) - ord('F') - 1)
        new_ans.append(str(value))
    return "".join(new_ans)



def main():
    n = int(input())
    s = input()

    if n == 1:
        el = hash(s)
        s = el + s
        print(s)
    else:
        print(s)
        curr_arr = list(s[10:])
        s_hash = "".join(s[:10])
        for i in range(len(curr_arr)):
            old_char = curr_arr[i]
            for j in range(26):
                curr_arr[i] = chr(ord('A') + j)
                curr_str = "".join(curr_arr)
                new_hash = hash(curr_str)
                if s_hash == new_hash:
                    print(curr_str)
                    return
            curr_arr[i] = old_char
        else:
            print("".join(curr_arr))



main()