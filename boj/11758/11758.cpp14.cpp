#include <bits/stdc++.h>
using namespace std;
int ccw(int x1,int y1,int x2,int y2,int x3,int y3){
	int temp=x1*y2+x2*y3+x3*y1;
	temp-=y1*x2+y2*x3+y3*x1;
	if(temp>0) return 1;
	else if(temp<0) return -1;
	return 0;
}
main(){
	int x1,y1,x2,y2,x3,y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	cout<<ccw(x1,y1,x2,y2,x3,y3);
}