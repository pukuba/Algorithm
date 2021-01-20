#include <iostream>
#include <algorithm>

using namespace std;
int main(){
	int d[1001][3];
	int N;
	cin>>N;
	
	for(int i=1; i<=N; i++){
		int R,G,B;
		cin>>R>>G>>B;
		d[i][0]=min(d[i-1][1],d[i-1][2])+R;
		d[i][1]=min(d[i-1][0],d[i-1][2])+G;
		d[i][2]=min(d[i-1][0],d[i-1][1])+B;
	}
	cout<<min(d[N][0],min(d[N][1],d[N][2]))<<'\n';
} 