#include <iostream>
#include <algorithm>

using namespace std;
int main(){
	int input;
	for(int t=1; t<=3; t++){
		cin>>input;
		int cnt=0,temp=0,temp2=0,ans=0;
		for(int i=1; i<=8; i++){
			temp = input%10;
			if(temp2!=temp){
				temp2=temp;
				cnt=1;
			} else {
				cnt++;
			}
			ans = max(ans,cnt);
			input/=10;
		}
		cout<<ans<<'\n';
	}
}