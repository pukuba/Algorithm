#include <iostream>
#include <string>

using namespace std;
int main(){
	int n,ans=0;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		if(s=="anj") ans++; 
	} 
	(ans>0)?cout<<"뭐야;":cout<<"뭐야?";
}