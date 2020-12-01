#include <iostream>

using namespace std;
int main(){
	int T,g,y,s1,s2;
	cin>>T;
	for(int i=1; i<=T; i++){
		y=0,g=0;
		for(int j=1; j<=9; j++){
			cin>>s1>>s2;
			y+=s1,g+=s2;
		}
		if(g>y){
			cout<<"Korea"<<'\n';
		}
		if(y>g){
			cout<<"Yonsei"<<'\n';
		} 
		if(y==g)cout<<"Draw"<<'\n';
	}
}