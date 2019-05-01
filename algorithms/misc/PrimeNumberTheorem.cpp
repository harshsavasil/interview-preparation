#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
int arr[100000001];
const int SIZE = 100000000;
const int LIMIT = sqrt(SIZE)+1;
 
bool prime[SIZE];
 
void sieve() 
{
    for(int i=0;i<SIZE;i++) prime[i]=true;
    prime[1]=false;
    for(int i=2;i<=LIMIT;i++) 
    {
        if(prime[i]) 
        {
            for(int j=2*i;j<SIZE;j+=i)
            {
                prime[j]=false;
            }   
       }
    }   
}
 
bool isPrime(int n) 
{
    return prime[n];
}
int main()
{
    int n,count1=0,i;
    cin>>n;
    sieve();
    for(i=2;i<=100000000;i++)
    {
        if(isPrime(i)==true)
        {
            count1+=1;
        }   
        arr[i]=count1;
    }
    cout<<arr[2]<<" "<<arr[3]<<" "<<arr[5]<<endl;
    while(n!=0)
    {
        cout << fixed << showpoint;
        cout << setprecision(1);
        cout<<((abs(arr[n]-(n/log(n)))*100)/arr[n])<<endl;
        cin>>n;
    }
}
