#include <iostream>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	long long ans=0;
	int N,C,B;
	cin>>N;
	long long int A[N];
	for(int i=1; i<=N; i++){
		cin>>A[i];
	}
	cin>>B>>C;
	for(int i=1; i<=N; i++){
		A[i]-=B;
		ans++;
		if(A[i]>0){
			if(A[i]%C==0){
				ans+=A[i]/C;
			}
			else if(A[i]%C!=0){
				ans+=A[i]/C+1;
			}
		}
	}	
	cout<<ans;
} 