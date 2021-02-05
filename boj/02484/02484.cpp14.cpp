#include <iostream>
#include <algorithm>

using namespace std;
int main(){
	int t,ans=0;
	cin>>t;
	while(t--){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(a==b&&a==c&&a==d){
			if(ans<a*5000+50000){
				ans=a*5000+50000;
			}
		}
		else if(a==b&&b==c){
			if(ans<a*1000+10000){
				ans=a*1000+10000;
			}
		}
		else if(a==b&&b==d){
			if(ans<a*1000+10000){
				ans=a*1000+10000;
			}
		}
		else if(a==c&&c==d){
			if(ans<a*1000+10000){
				ans=a*1000+10000;
			}
		}
		else if(b==c&&c==d){
			if(ans<b*1000+10000){
				ans=b*1000+10000;
			}
		}
		else if(a==b&&c==d){
			if(ans<2000+500*a+500*c){
				ans=2000+500*a+500*c;
			}
		} 
		else if(a==c&&b==d){
			if(ans<2000+500*a+500*b){
				ans=2000+500*a+500*b;
			}
		}
		else if(c==b&&a==d){
			if(ans<2000+500*a+500*b){
				ans=2000+500*a+500*b;
			}
		}
		else if(a==b||a==c||a==d){
			if(ans<1000+100*a){
				ans=1000+100*a;
			}
		}
		else if(b==c||b==d){
			if(ans<1000+100*b){
				ans=1000+100*b;
			}
		}
		else if(c==d){
			if(ans<1000+100*c){
				ans=1000+100*c;
			}
		}
		else{
		if(ans<max({a,b,c,d})*100){
			ans=max({a,b,c,d})*100;
			}
		}
	}
	cout<<ans;
}