h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())

time1 = h1*60 + m1
time2 = h2*60 + m2

answer = 0

def Convert(value):
    if value < 10:
        value = '0' + str(value)
    return str(value)



while time1 != time2+1:
    if m1 >= 60:
        h1 += 1
        m1 = 0
    if h1 >= 24:
        h1 = 0
    
    flag = False
    if Convert(h1) == Convert(m1):
        answer += 1
        flag = True
    if Convert(h1) == Convert(m1)[::-1] and not flag:
        answer += 1
        flag = True
    if Convert(h1) + Convert(m1) in "0123456789" and not flag:
        answer += 1
            
    m1 += 1
    time1 = h1*60 + m1
    time2 = h2*60 + m2    

        
print(answer)
    
        