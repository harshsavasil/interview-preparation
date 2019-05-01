for i in xrange(0,int(raw_input())): #More than 2 lines will result in 0 score. Do not leave a blank line also
    print pow(pow(10,i)+s,2);s = pow(10,i)+s
