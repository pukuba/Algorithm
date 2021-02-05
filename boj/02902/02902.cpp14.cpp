#include <iostream>
#include <string>

using namespace std;
int main(){
	string a;
	getline(cin,a);
	int len=a.size();
	for(int i=0; i<len; i++){
		if(i==0){
			cout<<a[i];
		}
		else if(a[i]=='-'){
			cout<<a[i+1];
		}
	}
}