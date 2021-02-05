#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	string s;
	int c[26]={0,};
	getline(cin, s);
	for(int i=0; i<s.size(); i++)
		c[s[i]-'a']++;
	
	for(int i=0; i<26; i++)
		cout << c[i] << " ";
} 