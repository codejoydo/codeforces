raw = raw_input()
a = raw.split(':')
h = int(a[0])
m = int(a[1])
k = input()
h = (h + k/60) % 24
m += k%60
if m>=60:
  m %= 60
  h = (h + 1) % 24
hh = []
mm = []
hh.append(str(h%10))
hh.append(str(h/10))
mm.append(str(m%10))
mm.append(str(m/10))
ans = hh[1] + hh[0] + ':' + mm[1] + mm[0]
print ans
