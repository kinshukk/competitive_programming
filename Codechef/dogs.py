t = int(raw_input())
for a in xrange(t):
    s, v = [int(i) for i in raw_input().split()]
    print '{0:.10f}'.format((2.0*s)/(3.0*v))
