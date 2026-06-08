h1 = int(input())
m1 = int(input())
h2 = int (input())
m2 = int (input())
 def is_beautiful (h,m)
if h == m 
return True
h_tr = f"{h:02d}
m_tr = f"{m:02d}
if m_str == h_str[1] + h_str[0]
return True
s = h_str + m_str
for i in rage(3):
if int (s[i+1]) !=int(s[i]) + 1
return True
count = 0
h,m = h1, m1
while true
if  is_beautiful(h,m)
m+=1
if m==60
m= 0
h+=1
if h == h2 and m == m2 :
break 
if is_beautiful(h2,m2):
count +=1

print(count)
