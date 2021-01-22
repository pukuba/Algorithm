#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int cmp(int a,int b){
	return a>b;
}
int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	sort(arr.begin(),arr.end(),cmp);
	for(int i=0; i<n; i++){
		cout<<arr[i]<<'\n';
	}
} 