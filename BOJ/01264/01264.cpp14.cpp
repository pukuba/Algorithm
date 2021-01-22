#include <iostream>
#include <cstring>

using namespace std;
int main(){
	char str[256];
	string st;
	int max;
	while(1){
	int	ans=0;
	getline(cin,st);
	if(st[0]=='#'){
		return 0;
	}
	max=st.size();
	for(int i=0; i<max; i++){
		if(st[i]=='a'||st[i]=='e'||st[i]=='i'||st[i]=='o'||st[i]=='u'){
			ans++;
		}
		else if(st[i]=='A'||st[i]=='E'||st[i]=='I'||st[i]=='O'||st[i]=='U'){
			ans++;
		}
	}
	cout<<ans<<'\n';
}
} 