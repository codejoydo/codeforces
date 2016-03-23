a = raw_input()
b = raw_input()
c = raw_input()
d = raw_input()
x = ''
y = ''
if a[0] != 'X':
    x = x + a[0] 
if a[1] != 'X':
    x = x + a[1] 
if b[1] != 'X':
    x = x + b[1] 
if b[0] != 'X':
    x = x + b[0] 
if c[0] != 'X':
    y = y + c[0] 
if c[1] != 'X':
    y = y + c[1] 
if d[1] != 'X':
    y = y + d[1] 
if d[0] != 'X':
    y = y + d[0] 
foo = ['ABC','BCA','CAB']
bar = ['CBA','BAC','ACB']
if x in foo and y in foo:
    print "YES"
elif x in bar and y in bar:
    print "YES"
else:
    print "NO"
