#include <iostream>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int i;
	cin>>i;
	i++;
	while(i--){
		if(i==0){
			return 0;
		}
		cout<<i<<'\n';
	}
	return 0;
}