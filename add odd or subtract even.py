n=int(input())
l=[]
for i in range(n):
    ll=input().split()
    k=int(ll[1])-int(ll[0])
    if k==0:
        l.append(0)
    elif k>0:
        if k%2==0:
            l.append(2)
        else:
            l.append(1)
    else:
        if k%2==0:
            l.append(1)
        else:
            l.append(2)
for i in l:
    print(i)

