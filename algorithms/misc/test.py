n=raw_input()
for i in range(0,int(n)):
    x=float(raw_input())
    x=(x**2+x)/(2*(x**2+x+1))
    print("%.5f" % x)
