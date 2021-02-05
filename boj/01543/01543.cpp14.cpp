#include <bits/stdc++.h>

using namespace std;
int main(){
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	int s2len=s2.size(),s1len=s1.size(),ans=0;
	if(s2len>s1len){
		cout<<"0";
		return 0;
	} for(int i=0; i<s1len; i++){
		bool check=false;
		if(s1[i]==s2[0]){
			for(int j=i; j<i+s2len; j++){
				if(s1[j]!=s2[j-i]) check=true;
			}
			if(!check){
				ans++;
				i+=s2len-1;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}