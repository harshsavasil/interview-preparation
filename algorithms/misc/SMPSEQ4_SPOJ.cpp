#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
	int n,m,i,j;
	cin>>n;
	int A[n];
	for(i=0;i<n;i++)
		cin>>A[i];
	cin>>m;
	int B[m];
	for(i=0;i<m;i++)
		cin>>B[i];
	int k =max(m,n);
	vector<int> v(k);
	vector<int>::iterator it;
	it = set_intersection(A,A+n,B,B+m,v.begin());
	v.resize(it-v.begin());
	for (it=v.begin(); it!=v.end(); ++it)
    	cout<<*it<<" ";
}