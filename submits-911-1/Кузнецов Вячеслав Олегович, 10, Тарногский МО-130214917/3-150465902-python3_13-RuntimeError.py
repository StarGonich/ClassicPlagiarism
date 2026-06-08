n = int(input());
t = int(input());
i = 1;
c = 0;
t1 = [];
t2 = [];
while i<=n :
	t1[i], t2[i] = map(int, input().split());
	if (t2[i] - t1[i-1] < 3600) and ((t2[i] - t1[i]) + (t2[i-1] - t1[i-1]) > t):
		c = (t1[i] + (t - (t2[i-1] - t1[i-1]))) - 3599;
	i = i + 1;
if c != 0:
	print(c);
else:
	print(-1);