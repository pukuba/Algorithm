#include <iostream>
#include <algorithm>

using namespace std;
int main(){
	int T;
	cin>>T;
	int* q=new int[T];
	for(int i=0; i<T; i++){
		cin>>q[i];
	}
	sort(q,q+T);
	for(int i=0; i<T; i++){
		cout<<q[i]<<'\n';
	}
}