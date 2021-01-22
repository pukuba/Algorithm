#include <iostream>

using namespace std;
int main(){
	int dp[12];   //dp문제 dp[i] = dp[i-3]+dp[i-2]+dp[i-1]	;
	int test;
	cin>>test;
	while(test>0){
	int input;
	cin>>input;
	dp[1]=1,dp[2]=2,dp[3]=4;
	for(int i=4; i<=input; i++){
		dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
	} 
	cout<<dp[input]<<endl;
	test--;
}
}