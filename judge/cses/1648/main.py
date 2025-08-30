n, q = [int(i) for i in input().split()]

arr = [int(i) for i in input().split()]
f = [0]*(4*n+5)

def Update(id, l, r, k, u):
    if r < k or k < l:
        return
    
    if l == r:
        f[id] = u
        return
    
    m = (l+r)//2
    Update(2*id+1, l, m, k, u)
    Update(2*id+2, m+1, r, k, u)

    f[id] = f[2*id+1] + f[2*id+2]

def Get_sum(id, l, r, u, v):
    if r < u or v < l:
        return 0
    
    if u <= l and r <= v:
        return f[id]
    
    m = (l+r)//2
    return Get_sum(2*id+1, l, m, u, v) + Get_sum(2*id+2, m+1, r, u, v)


for i in range(n):
    Update(0, 0, n-1, i, arr[i])

for i in range(q):
    type, x, y = [int(i) for i in input().split()]
    x -= 1
    
    if type == 1:
        Update(0, 0, n-1, x, y)
    elif type == 2:
        y -= 1
        print(Get_sum(0, 0, n-1, x, y))


