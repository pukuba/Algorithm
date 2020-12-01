#include <iostream>

using namespace std;
int main(){
	int a[10],b[10],win=0,lose=0;
	for(int i=0; i<10; i++){
		cin>>a[i];
	}
	for(int i=0; i<10; i++){
		cin>>b[i];
	}
	for(int i=0; i<10; i++){
		if(a[i]>b[i]){
			win++;
		}
		else if(a[i]<b[i]){
			lose++;
		}
	}
	if(win>lose){
		cout<<"A"<<'\n';
	}
	else if(lose>win){
		cout<<"B"<<'\n';
	}
	else{
		cout<<"D"<<'\n';
	}
}