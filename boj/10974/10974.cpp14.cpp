#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 
int main(){
	int n;
	cin>>n;
	vector<int> a;
	for(int i=1; i<=n; i++){
		a.push_back(i);
	}
	do{
		for(int i=0; i<a.size(); i++){
			cout<<a[i]<<' ';
		}
		cout<<'\n';
	}while(next_permutation(a.begin(),a.end()));
}