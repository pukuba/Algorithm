#include <iostream>

using namespace std;
int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	for(int i=0; i<=d/a; i++){
		for(int j=0; j<=d/b; j++){
			for(int k=0; k<=d/c; k++){
				if(i*a+j*b+k*c==d){
					cout<<"1"<<'\n';
					return 0;
				}
			}
		}
	} 
	cout<<"0"<<'\n';
}