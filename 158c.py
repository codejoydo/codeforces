n = input()
cwd = []

def print_cwd(string):
    s2 = ""
    for part in string:
        s2 = s2 + "/" + part
    s2 = s2 + "/"
    print s2

for i in xrange(n):
    s = raw_input()
    cmd = s.split(' ')
    if cmd[0] == "pwd":
        print_cwd(cwd)
    elif cmd[0] == "cd":
        if cmd[1][0] == '/':
            cwd = []
        cmd[1] = cmd[1].strip(' ')
        cmd[1] = cmd[1].strip("/")
        s1 = cmd[1].split('/')
        for part in s1:
            if part == "..":
                del cwd[-1]
            else:
                cwd.append(part)

