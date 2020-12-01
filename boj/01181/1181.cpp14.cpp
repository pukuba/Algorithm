#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
bool comp(string s1,string s2){
	if(s1.size()==s2.size()){
		return s1<s2;
	}
	return s1.size()<s2.size();
}
int main(){
	int T;
	cin>>T;
	string s[20001];
	for(int i=0; i<T; i++){
		cin>>s[i];
	}
	for(int i=1; i<T; i++){
		for(int j=0; j<i; j++){
			if(s[i]==s[j]){
				s[j]="NULL";
			}
		}
	}
	sort(s,s+T,comp);
	for(int i=0; i<T; i++){
		if(s[i]=="NULL"){
			continue;
		}
		cout<<s[i]<<'\n';
	}
}