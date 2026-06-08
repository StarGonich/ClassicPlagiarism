h1 = int(input()) 
m1 = int(input()) 
h2 = int(input()) 
m2 = int(input()) 

def good(hours, minutes):
    hs = f"{hours:02d}"
    ms = f"{minutes:02d}"
    if hours == minutes:
        return True
    
    if ms == hs[1] + hs[0]:
        return True
    
    t = hs + ms
    if (int(t[1]) == int(t[0]) + 1 and
        int(t[2]) == int(t[1]) + 1 and
        int(t[3]) == int(t[2]) + 1):
        return True
    return False

count = 0


h = h1
m = m1

while True:
    
    if good(h,m):
        count = count + 1 
    
    if h == h2 and m == m2:
        break
    
  
    m = m + 1
    
    
    if m == 60:
        m = 0
        h = h + 1
      
        if h == 24:
            h = 0

print(count)
