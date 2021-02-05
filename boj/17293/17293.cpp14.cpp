#include <bits/stdc++.h>

using namespace std;
int main(){
	int n;
	cin>>n;
	int save=n;
	n++;
	while(n>1){
		n--;
		if(n!=1){
			cout<<n<<" bottles of beer on the wall, "<<n<<" bottles of beer.\n";
			if(n-1!=1) cout<<"Take one down and pass it around, "<<n-1<<" bottles of beer on the wall.\n\n";	
			else cout<<"Take one down and pass it around, "<<n-1<<" bottle of beer on the wall.\n\n";				
		}
		if(n==1 && save!=1){
			cout<<n<<" bottle of beer on the wall, "<<n<<" bottle of beer.\n";
			cout<<"Take one down and pass it around, no more bottles of beer on the wall.\n\n";
		}
		if(n==1 && save==1){
			cout<<n<<" bottle of beer on the wall, "<<n<<" bottle of beer.\n";
			cout<<"Take one down and pass it around, no more bottles of beer on the wall.\n\n";
		}
	}
	if(save==1){
		cout<<"No more bottles of beer on the wall, no more bottles of beer.\n";
		cout<<"Go to the store and buy some more, "<<save<<" bottle of beer on the wall.";
	}
	else{
		cout<<"No more bottles of beer on the wall, no more bottles of beer.\n";
		cout<<"Go to the store and buy some more, "<<save<<" bottles of beer on the wall.";
	}
}