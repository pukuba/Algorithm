#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	string str;
	string tmp[1001];
	cin>>str;
	int len = str.length();
	
	for(int i=0; i<len; i++){
		tmp[i] = str.substr(i,len);
	}
	sort(tmp,tmp+len);
	for(int i =0; i< len; i++){
		cout<<tmp[i]<<'\n';
	}
	return 0;
}