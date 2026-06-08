# Read the input
N = int(input())
T = int(input())

# Initialize a list to store the advertisement intervals
ads = []

# Read the advertisement intervals
for _ in range(N):
    t1, t2 = map(int, input().split())
    ads.append((t1, t2))

# Sort the advertisement intervals by their start time
ads.sort(key=lambda x: x[0])

# Check for any interval of 3600 seconds with more than T seconds of advertisements
for i in range(len(ads) - 1):
    start = ads[i][0]
    end = start + 3600
    total_time = 0

    # Check the advertisements within the current interval
    while i < len(ads) and ads[i][0] < end:
        total_time += ads[i][1] - ads[i][0]
        i += 1

    # If the total advertisement time exceeds T, print the start time of the interval
    if total_time > T:
        print(start)
        break
else:
    # If no such interval is found, print -1
    print(-1)
