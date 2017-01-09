#prints out the least number of bits to use for a given power of ten
import math

for i in xrange(1, 20):
    for j in [15, 16, 31, 32, 63, 64]:
        if math.pow(2, j) > math.pow(10, i):
            print "10^{} < 2^{}" .format(i, j)
            break
