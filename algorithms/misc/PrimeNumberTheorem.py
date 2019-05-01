import math

primes_list=[]
def primes(n):
  if n<=3:
    return n>1
  elif n%2==0 or n%3==0:
    return 0
  for i in range(5,int(math.sqrt(n))+1,6):
    if n%i==0 or n%(i+2)==0:
      return 0
  return 1

def main():
  n=input()
  count=0
  primes_list.append(0)
  for i in range(1,100000000):
    if primes(i)==1:
      count+=1
    primes_list.append(count)
  print type(n)
  x= (abs(primes_list[n]-(n/math.log(n)))/primes_list[n])*100
  n=input()

if __name__ == '__main__':
  main()
