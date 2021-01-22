#include <iostream>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int input,sum=0;
	cin>>input;
	input++;
	while(input--){
		if(input==0){
			break;
		}
		sum +=input;
	}
	cout<<sum<<'\n';
} 