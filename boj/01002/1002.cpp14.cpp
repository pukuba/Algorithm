#include <iostream>
#include <cmath>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false),cin.tie(NULL);
	int x1,y1,r1,x2,y2,r2,T,ans,q;
	cin>>T;
	while(T--){
		double dis;
		cin>>x1>>y1>>r1>>x2>>y2>>r2;
		if(r2>r1) q=r2-r1;
		else q=r1-r2;
		int x3=x1-x2;
		int y3=y1-y2;
		dis=sqrt(pow(x3,2)+pow(y3,2));
		if(x1==x2&&y1==y2){
			if(r1==r2){
				cout<<"-1"<<'\n';
			}
			else {
				cout<<"0"<<'\n';
			}
		}
		else{
			if(dis<r1+r2&&q < dis){
				cout<<"2"<<'\n';
			}	
			else if(dis==r1+r2||dis==q){
				cout<<"1"<<'\n';
			}
			else 
				cout<<"0"<<'\n';
			}
		}
	} 