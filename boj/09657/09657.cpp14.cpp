#include <iostream>

using namespace std;
int main(){
	bool d[1001]{false,};
	int N;
	cin>>N;
	d[1]=d[3]=d[4]=true;
	for(int i=5; i<=N; i++){
		if(!d[i-1]||!d[i-3]||!d[i-4]) d[i]=true;
	}
	if(d[N]==true){
		cout<<"SK"<<'\n';
	}
	else{
		cout<<"CY"<<'\n';
	}
} 