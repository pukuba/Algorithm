#include <iostream>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	int a,b,c,count=0;
	cin>>a>>b>>c;
	while(b!=c){
		b=b/2+b%2;
		c=c/2+c%2;
		count++;
	}
	cout<<count;	
}