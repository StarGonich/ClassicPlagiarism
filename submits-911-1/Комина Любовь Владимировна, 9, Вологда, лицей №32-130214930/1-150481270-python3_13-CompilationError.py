def is_beautiful(hour, minute):
  h_str = str(hour).zfill(2)
  m_str = str(minute).zfill(2)
  time_str = h_str + m_str

  if h_str == m_str:
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
