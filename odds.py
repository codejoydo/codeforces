for _ in range(int(input())):
    n, x = map(int, input().split())
    arr=list(map(int,input().split()))
    odd=0
    even=0
    for i in arr:
        if i%2==0:
            even+=1
        else:
            odd+=1
    if n>=x and odd!=0:
        print("Yes")
    else:
        print("No")