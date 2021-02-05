#include <iostream>

using namespace std;
int maxx(int q,int w){
	if(q>=w){
		return q;
	}
	else{
		return w;
	}
}
int main(){
	int t,max=0;
	cin>>t;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		if(a==b&&a==c){
			if(max<a*1000+10000){
				max=a*1000+10000;
			}
		}
		else if(a==b||a==c||b==c){
			if(a==b){
				if(max<a*100+1000){
					max=a*100+1000;
				}
			}
			else if(b==c){
				if(max<b*100+1000){
					max=b*100+1000;
				}
			}
			else if(c==a){
				if(max<c*100+1000){
					max=c*100+1000;
				}
			}
		}
		else{
			if(max<maxx(a,(maxx(b,c)))*100){
				max=maxx(a,(maxx(b,c)))*100;
			}
		}
	}
	cout<<max;
}