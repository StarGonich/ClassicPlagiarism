def bam(h, m):
	#print(f"{h}:{m}")
	if (h == m) or (h == m[::-1]) or (h + m in ["0123", "1234", "2345"]):
		#print(f"{h}:{m}")
		return True
	#print(f"{h}:{m}")
	return False


def form(num):
    #print(f"!! {num // 60}")
    if num // 60 >= 24:
    	if num // 60 - 24 < 10:
        	h = "0" + str(num // 60 - 24)
    	else:
        	h = str(num // 60 - 24)
    else:
    	if num // 60 < 10:
        	h = "0" + str(num // 60)
    	else:
        	h = str(num // 60)
    #print(f"! {num // 60}")
    if num % 60 < 10:
        m = "0" + str(num % 60)
    else:
        m = str(num % 60)
    #if num // 60 < 10:
        #h = "0" + str(num // 60)
    #else:
        #h = str(num // 60)
    return h, m


h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())

time1 = h1 * 60 + m1
time2 = h2 * 60 + m2

if time2 < time1:
	time2 += 24 * 60

ans = 0
for t in range(time1, time2 + 1):
    h, m = form(t)
    if bam(h, m):
        ans += 1

print(ans)
