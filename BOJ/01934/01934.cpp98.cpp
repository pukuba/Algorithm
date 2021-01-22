#include <iostream>

using namespace std;

int LCM(int num,int num2)
{
	long long int firstnum1=num,firstnum2=num2;
	if(num==0||num2==0)
	{
		cout<<"0";
	}
	else if(num==1||num2==1)
	{
		cout<<num*num2;
	}
	else
	{
		while(num!=num2)
		{
			if(num==num2)
			{
				cout<<num;
				break;
			}
			if(num>num2)
			{
				num2+=firstnum2;
			}
			else if(num<num2)
			{
				num+=firstnum1;
			}
			
		}
		cout<<num;
	}
}
int main()
{
	int input,input2,input3;
	cin>>input;
	for(int a=1; a<=input; a++)
	{
		cin>>input2>>input3;
		LCM(input2,input3);
		cout<<endl;	
	}
}