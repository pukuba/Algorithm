#include <queue>
#include <iostream>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false),cin.tie(NULL);
	queue<int> q;
	int T;
	cin>>T;
	string str;
	while(T--){
		cin>>str;
		if(str=="push"){
			int x;
			cin>>x;
			q.push(x);
		}
		if(str=="pop"){
			if(!q.empty()){
				cout<<q.front()<<'\n';
				q.pop();
			}
			else{
				cout<<"-1\n";
			}
		}
		if(str=="size"){
			cout<<q.size()<<'\n';
		}
		if(str=="empty"){
			cout<<q.empty()<<'\n';
		}
		if(str=="front"){
			if(!q.empty()){
				cout<<q.front()<<'\n';
			}
			else{
				cout<<"-1\n";
			}
		}
		if(str=="back"){
			if(!q.empty()){
				cout<<q.back()<<'\n';
			}
			else{
				cout<<"-1\n";
			}
		}
	}
}