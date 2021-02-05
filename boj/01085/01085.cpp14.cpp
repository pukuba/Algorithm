#include <iostream>
#include <algorithm>

int main(){
	int x,y,w,h;
	std::cin>>x>>y>>w>>h;
	int xans=w-x;
	int yans=h-y;
	int ans=x;
	if(ans>xans) ans=xans;
	if(ans>yans) ans=yans;
	if(ans>y) ans=y;
	std::cout<<ans<<'\n'; 
}