#include <iostream>

using namespace std;
int main(){
	int i;
	cin>>i;
	if(i%4==0&&i%100!=0||i%400==0){
		cout<<1;
	}
	else{
		cout<<0;
	}
}