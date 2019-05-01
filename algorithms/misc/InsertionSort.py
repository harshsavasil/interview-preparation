class InsertionSort:
    def main():
        n=int(input("enter the no. of numbers to be sorted:"))
        a=[]
        for i in range(0,n):
            a.append(int(input()))
        for i in range(1,n):
            key=a[i]
            j=i-1
            while j>=0 and key<a[j]:
                a[j+1]=a[j]
                j=j-1
            a[j+1]=key
        print a
    if __name__ == "__main__":
        main()
