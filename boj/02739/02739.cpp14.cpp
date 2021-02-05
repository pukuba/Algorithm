#include <iostream>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int gugu;
	cin>>gugu;
	for(int i=1; i<=9; i++){
		cout<<gugu<<" * "<<i<<" = "<<gugu*i<<'\n';
	}
}