#include <bits/stdc++.h>

using namespace std;
int arr[1111],n;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	for(int i=1; i<=1000; i++){
		string s = to_string(i);
		bool check = false;
		if(s.size() <= 2) check = true; 
		else{
			if(s[1]-'0' - s[0]-'0' == s[2]-'0' - s[1]-'0') check = true;
		}
		if(check) arr[i] = arr[i-1] +1;
		else arr[i] = arr[i-1];
	}
	cin>>n;
	cout<<arr[n];
}