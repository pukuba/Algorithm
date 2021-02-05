//Obtaining the 2007 Day of the Week
#include <iostream>
#include <string>

using namespace std;
//Data calculation function;
int getData(int getMonth,int getDays)
{
	int plus=0;
	int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	string days[7]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
	for(int j=0; j<getMonth; j++)
	{
		plus +=month[j];
	}
	plus+=getDays;
	plus %=7;
	cout<<days[plus];
}
int main()
{
int input1,plus,input2;
cin>>input1>>input2;
getData(input1,input2);
}