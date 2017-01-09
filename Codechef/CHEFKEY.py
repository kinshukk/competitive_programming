t = int(raw_input())
for i in xrange(t):
    n, m, c = [int(i) for i in raw_input().split()]

    if c > n*m:
        print '0'
        next

    mx = max(n, m)
    mn = min(n, m)
    count = 0
    arr = []
    for j in xrange(1, c):
        if c%j == 0:
            x = c/j
            if x <= mx and j <= mx:
                count = count + 1
    print '{}'.format(count)
