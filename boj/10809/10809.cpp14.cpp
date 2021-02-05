#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	string input; 
	cin>>input;
	int alpha[27];
	for(int i=0; i<26; i++){
		alpha[i]=-1;
	}
	for(int i=0; i<input.length(); i++){
		if(alpha[input[i]-97]==-1){
			alpha[input[i]-97]=i;
		}
	}
	for(int i=0; i<26; i++){
		cout<<alpha[i]<<' ';
	}
}