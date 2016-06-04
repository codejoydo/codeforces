a = raw_input().split(' ')
cplus = 1
cminus = 0
s = int(a[-1])
for c in a:
	if c == "+":
		cplus += 1
	elif c == "-":
		cminus += 1

l1 = cplus
r1 = cplus * s
l2 = s + cminus
r2 = s + s * cminus
l = max(l1,l2)
r = min(r1,r2)
if l>r:
	print "Impossible"
	quit()
plus = l
minus = l - s
iplus = int(plus / cplus)
rplus = plus % cplus
if cminus != 0:
	iminus = int(minus / cminus)
	rminus = minus % cminus
else:
	iminus = 0
tp = 0
ans = ""
for c in a:
	if c == "+" or tp == 0:
		tp = 1
		k = iplus
		if rplus:
			k += 1
			rplus -= 1
		plus -= k
		if c == a[0]:
			ans = ans + str(k)
		else: 
			ans = ans + " + " + str(k)
	elif c == "-":
		k = iminus
		if rminus:
			k += 1
			rminus -= 1
		minus -= k
		ans = ans + " - " + str(k)
ans = ans + " = " + str(s)
print "Possible"
print ans
