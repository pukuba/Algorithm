#include <iostream>
#include <queue>

using namespace std;
int main(){
	int n,m,f;
	queue<int> q;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		q.push(i);
	}
	cout<<"<";
	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
			q.push(q.front());
			q.pop();
		}
		cout<<q.front()<<", ";
		q.pop();
	}
	cout<<q.front()<<">"<<'\n';
}