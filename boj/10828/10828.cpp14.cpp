#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	stack<int> S;
	int t;
	string str;
	cin>>t;
	while(t--){
		cin>>str;
		if(str=="push"){
			int x;
			cin>>x;
			S.push(x);
		}
		if(str=="pop"){
			if(S.empty()){
				cout<<"-1\n";
			}
			if(!S.empty()){
				cout<<S.top()<<'\n';
				S.pop();
			}
		}
		if(str=="size"){
			cout<<S.size()<<'\n';
		}
		if(str=="empty"){
			if(S.empty()){
				cout<<"1"<<'\n';
			}
			if(!S.empty()){
				cout<<"0"<<'\n';
			}
		}
		if(str=="top"){
			if(S.empty()){
				cout<<"-1\n";
			}
			if(!S.empty()){
				cout<<S.top()<<'\n';
			}
		}
	}
}