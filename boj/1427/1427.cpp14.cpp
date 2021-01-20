#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int main(){
	char c[10];
	cin>>c;
	sort(c,c+strlen(c));
	for(int i=strlen(c)-1; i>=0; i--){
		cout<<c[i];
	}
}