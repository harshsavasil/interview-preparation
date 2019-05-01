# Enter your code here. Read input from STDIN. Print output to STDOUT
str = raw_input()
l = str.split()
N = int(l[0])
Jess = int(l[1])
strength = raw_input()
rocks = strength.split()
count =0
ans=N-1
for i in range(0,N):
    if int(rocks[i]) > Jess :
        count= count+1
    if count ==2:
        ans = i-1
        break
print ans
