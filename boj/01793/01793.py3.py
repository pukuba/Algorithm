import sys
d = [1,1,3,5,11]
for i in range(5,int(251)):
    d.append((d[i-1])+d[i-2]*2)
for i in sys.stdin:
	print(d[int(i)])