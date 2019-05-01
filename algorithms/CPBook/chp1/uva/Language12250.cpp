#include <string>
#include <iostream>
using namespace std;
int main()
{
	string x;
	int k=1;
	while(getline(cin,x))
	{
		if(x.compare("#")==0)
			return 0;
		if(x.compare("HELLO")==0)
			cout<<"Case "<<k<<": "<<"ENGLISH"<<endl;
		else if(x.compare("HOLA")==0)
			cout<<"Case "<<k<<": "<<"SPANISH"<<endl;
		else if(x.compare("HALLO")==0)
			cout<<"Case "<<k<<": "<<"GERMAN"<<endl;
		else if(x.compare("CIAO")==0)
			cout<<"Case "<<k<<": "<<"ITALIAN"<<endl;
		else if(x.compare("BONJOUR")==0)
			cout<<"Case "<<k<<": "<<"FRENCH"<<endl;
		else if(x.compare("ZDRAVSTVUJTE")==0)
			cout<<"Case "<<k<<": "<<"RUSSIAN"<<endl;
		k++;
	}
}
