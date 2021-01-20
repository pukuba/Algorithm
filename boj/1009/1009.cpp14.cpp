#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	long long int b,com;
	int a,m;
	int T;
	cin>>T;
	while(T>0)
	{
		cin>>a>>m;
		b=m;
		com=a;
		while(m>1)
		{
			com %=10;
			com *=a;
			m--;
		}
		com%=10;
		if(com==0)
		{
			com=10;
		}
		cout<<com<<endl;
		T--;
	}
}