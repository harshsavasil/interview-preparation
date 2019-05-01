#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
 
string removeLeadingZeroes(string x)
{
    int i,n,count=0;
    n=x.size();
    for(i=0;i<n;i++)
    {
        if(x[i]=='0')
            count++;
        else
            break;
    }
    string y = x.substr(count);
    return y;
}
string decimalToBinary(string x)
{
    string ans;
    int n=0;
    while(true)
    {
        int carry=0;
        if(x.size()==1 && stoi(x)==0)
        {
            ans='0'+ans;
            return ans;
        }
        else if(x.size()==1 && stoi(x)==1)
        {   
            ans='1'+ans;
            return ans;
        }
        n=x.size();
        //cout<<x<<" "<<n<<endl;
        if((x[n-1]-'0')%2==0)
        {
            ans='0'+ans;
        }
        else
        {
            ans='1'+ans;
        }
        for(int i=0;i<n;i++)
        {
            //cout<<stoi(to_string(carry)+x[i])<<" "<<carry<<" "<<x<<endl;
            int y=stoi(to_string(carry)+x[i]);
            if(y%2==0)
            {
                carry=0;
            }
            else if(y%2!=0)
            {
                carry=1;
            }
            y/=2;
            x[i]=y+'0';
            //cout<<x<<" "<<y<<" "<<stoi(to_string(carry)+x[i])/2<<" "<<x[i]<<endl;
            //cout<<x[i]<<endl;
        }
        x=removeLeadingZeroes(x);
    }
}
int makeEqualLength(string &str1, string &str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 < len2)
    {
        for (int i = 0 ; i < len2 - len1 ; i++)
            str1 = '0' + str1;
        return len2;
    }
    else if (len1 > len2)
    {
        for (int i = 0 ; i < len1 - len2 ; i++)
            str2 = '0' + str2;
    }
    return len1; 
}

string addBitStrings( string first, string second )
{
    string result;  // To store the sum bits
 
    // make the lengths same before adding
    int length = makeEqualLength(first, second);
    int carry = 0;  // Initialize carry
 
    // Add all bits one by one
    for (int i = length-1 ; i >= 0 ; i--)
    {
        int firstBit = first.at(i) - '0';
        int secondBit = second.at(i) - '0';
 
        // boolean expression for sum of 3 bits
        int sum = (firstBit ^ secondBit ^ carry)+'0';
 
        result = (char)sum + result;
 
        // boolean expression for 3-bit addition
        carry = (firstBit&secondBit) | (secondBit&carry) | (firstBit&carry);
    }
 
    // if overflow, then add a leading 1
    if (carry)  result = '1' + result;
 
    return result;
}
 
// A utility function to multiply single bits of strings a and b
int multiplyiSingleBit(string a, string b)
{  return (a[0] - '0')*(b[0] - '0');  }
 
long long int multiply(string X, string Y)
{
    int n = makeEqualLength(X, Y);
 
    if (n == 0) return 0;
    if (n == 1) return multiplyiSingleBit(X, Y);
 
    int fh = n/2;   // First half of string, floor(n/2)
    int sh = (n-fh); // Second half of string, ceil(n/2)
 
    // Find the first half and second half of first string.
    // Refer http://goo.gl/lLmgn for substr method
    string Xl = X.substr(0, fh);
    string Xr = X.substr(fh, sh);
 
    // Find the first half and second half of second string
    string Yl = Y.substr(0, fh);
    string Yr = Y.substr(fh, sh);
 
    // Recursively calculate the three products of inputs of size n/2
    long int P1 = multiply(Xl, Yl);
    long int P2 = multiply(Xr, Yr);
    long int P3 = multiply(addBitStrings(Xl, Xr), addBitStrings(Yl, Yr));
 
    // Combine the three products to get the final result.
    return P1*(1<<(2*sh)) + (P3 - P1 - P2)*(1<<sh) + P2;
}

// Driver program to test above functions
int main()
{
    int t;
    string a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        string x,y;
        x=decimalToBinary(a);
        y=decimalToBinary(b);
        cout<<multiply(x,y)<<endl;
    }
}