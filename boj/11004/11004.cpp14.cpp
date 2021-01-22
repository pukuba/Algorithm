#include <iostream>
#include <algorithm>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int a,b;
	cin>>a>>b;
	int c[a];
	for(int i=0; i<a; i++){
		cin>>c[i];
	}
	sort(c,c+a);
	cout<<c[b-1]<<'\n';
}