def is_mirror_time(h,m):
    time.str=f"{h:02d}{m:02d}"
    return time_str==time
str[::-1]
def count_beautiful_times(h1,m1,h2,m2):
    count=0
    for h in range(h1,h2+1):
        start_m=m1 if h==h1 else 0
        end_m=m2 if h==h2 else 59
    for m in range(start_m, end_m +1):
        if h==m or is_mirror_time(h,m):
            count+=1 
            return count
        h1,m1,h2,m2=map(int,input(). split())
        print(count_beautiful_times(h1,m1,h2,m2))