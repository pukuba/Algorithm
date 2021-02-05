#include <iostream>
#include <cstring>

using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		
		int tt=0,size=0;
		char s[21]={NULL,};
		scanf("%d %s",&tt,&s);
		size=strlen(s);
		for(int i=0; i<size; i++){
			for(int j=1; j<=tt; j++){
				cout<<s[i];
			}
		}
		cout<<'\n';
	}
}