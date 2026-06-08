def is_beautiful(hour, minute):
  h_str = str(hour).zfill(2)
  m_str = str(minute).zfill(2)
  time_str = h_str + m_str

  if h_str == m_str:
      return True

  if h_str == m_str[::-1]:
      return True

  if len(time_str) == 4:
    is_seq = True
    for i in range(3):
       if int(time_str[i+1]) - int(time_str[i]) !=1:
           is_seq = False
                 break
     if is_seq:
           return True

   return False

def count_beautiful_times(start_h, start_m, end_h, end_m):
   count = 0
   current_h = start_h
   current_m = start_m

   while True:
       if is_beautiful(current_h, current_m):
           count += 1

        
       if current_h == end_h and current_m == end_m:
                 break 

       current_m += 1
       if current_m == 60:
           current_m = 0
           current_h += 1
           if current_h == 24:
               current_h = 0 

      return count

start_hour = int(input())
start_minute = int(input())
end_hour = int(input())
end_minute = int(input())

result = count_beautiful_times(start_hour, start_minute, end_hour, end_minute)
print(result)