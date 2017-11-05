def pr(name):
	if len(name)==1:
		print(name[0])
	elif len(name)==2:
		print(name[0][0]+". "+name[1])
	else:
		print(name[0][0]+". "+name[1][0]+". "+name[2])

t = int(input().strip())
while(t):
	pr(input().strip().title().split())
	t-=1