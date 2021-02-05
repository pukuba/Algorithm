#include <iostream>
#include <queue>

using namespace std;
int main(){
	queue <int> a;
	int save;
	int N;
	cin>>N;
	for(int i=1; i<=N; i++){
		a.push(i);
	}
	while(1){
		if(a.size()!=1){
		
		a.pop();
		save=a.front();
	}
	if(a.size()!=1){
		a.push(save);
		a.pop();
	}
	else break;
	}
	cout<<a.front();
}