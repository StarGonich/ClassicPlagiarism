h1=int(input())
h2=int(input())
m1=int(input())
m2=int(input())
h1>=0, h2<=23, m1>=0, m2<=59
count = 0
cur_h = h1
cur_m = m1
while True:
  h_str = str(cur_h).zfill(2)
  m_str = str(cur_m).zfill(2)
  time_str = h_str + m_str
  if h_str == m_str:
    count += 1
  elif h_str == m_str[::-1]:
    count += 1
  elif len(time_str) == 4:
    if all(int(time_str[i]) + 1
  == int (time_str[i+1]) for i in range(3)):
        count += 1
  if cur_h == h2 and cur_m == m2:
    break
  cur_m += 1
  if cur_m>59:
    cur_m = 0
    cur_h += 1
    if cur_h > 23:
      cur_h = 0