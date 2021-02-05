#include <iostream>
#include <string>

using namespace std;
int main(){
	int n,cnt =1;
	string s;
	cin>>n>>s;
	if(n>1){
		for(int i=0; i<n; i++){
			if(s[i]=='S')
				cnt++;
			else
				i++,cnt++;
		}
	}
	if(n>cnt)
		cout<<cnt;
	else
		cout<<n;
}