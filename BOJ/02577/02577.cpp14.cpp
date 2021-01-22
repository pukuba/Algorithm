#include <iostream>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	int a,b,c,sum,ans[11]{0,};
	cin>>a>>b>>c;
	sum=a*b*c;
	while(sum!=0){
		ans[sum%10]+=1;
		sum/=10;
	} 
	for(int i=0; i<10; i++){
		cout<<ans[i];
		cout<<'\n';
	}
} 