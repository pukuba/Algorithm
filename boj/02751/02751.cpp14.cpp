#include <iostream>
#include <algorithm> 

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	int T;
	cin>>T;
	int* st = new int[T];
	for(int i=0; i<T; i++){
		cin>>st[i];
	}	
	sort(st,st+T);
	for(int i=0; i<T; i++){
		cout<<st[i]<<'\n';
	}
}