#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin>>s;
	
	long long result = 0;
	long long temp = 1;
	for(int i = s.length()-1; i>=0; i--)
	{
		if(s[i]>= '0' &&s[i]<='9')
			result +=(s[i]- '0')*temp;
		else
		{
			switch (s[i])
			{
				case 'A':
					result += 10 * temp;
					break;
				case 'B':
					result += 11 * temp;
					break;
				case 'C':
					result += 12 * temp;
					break;
				case 'D':
					result += 13 * temp;
					break;
				case 'E':
					result += 14 * temp;
					break;
				case 'F':
					result += 15 * temp;
					break;
					
			}
		}		
		temp *= 16;	
	}
	cout<<result;
}