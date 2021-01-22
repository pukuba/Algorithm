#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int a[26]{0,},max=-99;
	string s,ans;
	cin>>s;
	for(int i=0; i<s.size(); i++){
		if(s[i]<=90){
			a[s[i]-65]++;
			if(max<a[s[i]-65]){
			max=a[s[i]-65];
			ans=s[i];
		}
		}
		if(s[i]>=97){
			a[s[i]-97]++;
			if(max<a[s[i]-97]){
			max=a[s[i]-97];
			ans=s[i]-=32;
		}
		}
	}
	sort(a,a+26,cmp);
	if(a[0]==a[1]){
		cout<<"?"<<'\n';
	}
	else if(a[0]!=a[1]){
		cout<<ans<<'\n';
	}
}