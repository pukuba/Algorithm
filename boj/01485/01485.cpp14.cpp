#include <bits/stdc++.h>

using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		int ans=0;
		vector<pair<int,int> >  v(4),a(4);
		for(int i=0; i<4; i++) cin>>v[i].first>>v[i].second;
		double dis1=sqrt(pow(v[0].first-v[1].first,2) + pow(v[0].second-v[1].second,2));
		double dis2=sqrt(pow(v[0].first-v[2].first,2) + pow(v[0].second-v[2].second,2));
		double dis3=sqrt(pow(v[0].first-v[3].first,2) + pow(v[0].second-v[3].second,2));
		double _dis1=sqrt(pow(v[1].first-v[0].first,2) + pow(v[1].second-v[0].second,2));
		double _dis2=sqrt(pow(v[1].first-v[2].first,2) + pow(v[1].second-v[2].second,2));
		double _dis3=sqrt(pow(v[1].first-v[3].first,2) + pow(v[1].second-v[3].second,2));
		double __dis1=sqrt(pow(v[2].first-v[1].first,2) + pow(v[2].second-v[1].second,2));
		double __dis2=sqrt(pow(v[2].first-v[0].first,2) + pow(v[2].second-v[0].second,2));
		double __dis3=sqrt(pow(v[2].first-v[3].first,2) + pow(v[2].second-v[3].second,2));
		double ans1,ans2,ans3,ans4;
		if(dis1==dis2) ans1=dis3;
		else if(dis1==dis3) ans1=dis2;
		else if(dis2==dis3) ans1=dis1;
		else{
			cout<<0<<'\n';
			continue;
		}
		if(_dis1==_dis2) ans2=_dis3;
		else if(_dis1==_dis3) ans2=_dis2;
		else if(_dis2==_dis3) ans2=_dis1;
		else{
			cout<<0<<'\n';
			continue;
		}
		if(__dis1==__dis2) ans3=__dis3;
		else if(__dis1==__dis3) ans3=__dis2;
		else if(__dis2==__dis3) ans3=__dis1;
		else{
			cout<<0<<'\n';
			continue;
		}
		cout<<((ans1==ans2&& ans1==ans3))<<'\n';
	}
}