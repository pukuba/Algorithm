#include <iostream>
#include <cstring>

using namespace std;
int main(){
	int ans=10;
	char dish[51];
	cin>>dish;
	int len=strlen(dish);
	for(int i=1; i<len; i++){
		if(dish[i-1]==dish[i]){
			ans+=5;
		}
		else if(dish[i-1]!=dish[i]){
			ans+=10;
		}
	}
	cout<<ans;
}