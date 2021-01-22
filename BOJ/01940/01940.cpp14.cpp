#include <iostream>
#include <vector>

using namespace std;
int main(){
	int n,m,cnt =0;
	cin>>n>>m;
	vector <int> armor(n);
	for(int i = 0; i<n; i++){
		cin>>armor[i];
	}
	for(int i = 0; i<n -1; i++){
		for(int j = i+1; j<n; j++){
			if(armor[i]+armor[j]==m)
			cnt++;
		}
	}
	cout<<cnt<<'\n';
}