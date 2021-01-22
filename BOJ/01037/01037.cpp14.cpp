#include <iostream>
#include <algorithm> 

using namespace std;
int main(){
	ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
	int T;
	int* div= new int[T];
	cin>>T;
	for(int i=0; i<T; i++){
		cin>>div[i];
	}
	sort(div,div+T);
	cout<<div[0]*div[T-1];
}