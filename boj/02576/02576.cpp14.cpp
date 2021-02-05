#include <iostream>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	int T=7,a,ans=0,min=9999999,se=99999999; 
	while(T--){
		cin>>a;
		if(a%2!=0){
			ans+=a;
			se=a;
		}
		if(min>se){
			min=se;
		}
	}
	if(se==99999999){
		cout<<-1;
		return 0;
	}
	else
	cout<<ans<<'\n'<<min;
}