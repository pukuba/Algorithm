#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int T,st=1;
	cin>>T;
	while(T--){
		string a;
		cin>>a;
		for(int i=0; i<a.length(); i++){
			a[i]++;
			if(a[i]==91){
				a[i]=65;
			}
		}
		cout<<"String #"<<st<<'\n'<<a;
		cout<<"\n\n";
		st++;
	}
}