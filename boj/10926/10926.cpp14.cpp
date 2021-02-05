#include <iostream>

using namespace std;
int main(){
	string a;
	getline(cin,a);
	char b[3]{'?','?','!'};
	cout<<a<<b[0]<<b[1]<<b[2];
}