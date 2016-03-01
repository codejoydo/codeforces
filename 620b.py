a = [6,2,5,5,4,5,6,3,7,6]
line = raw_input()
l = line.split(' ')
p = int(l[0])
q = int(l[1])
ans = 0
for i in range(p,q+1):
    s = str(i)
    for c in s:
        x = int(c)
        ans += a[x]
print ans        
