#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
		int n;
		cin>>n;
		while(n--){
		int x,ans=1;
		cin>>x;
		vector<pair<int,int>> v1(x);
		for(int i=0; i<x; i++){
			cin>>v1[i].first>>v1[i].second;
		}
		sort(v1.begin(),v1.end());
		int standard = v1[0].second;
		for(int i=1; i<x; i++){			
			if(v1[i].second<standard){
				ans++;
				standard=v1[i].second;
			}
		}
		cout<<ans<<'\n';
		}
		
}