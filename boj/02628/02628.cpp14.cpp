#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int cmp(int a,int b){
	return a>b;
}
int main(){
	int x,y;
	cin>>x>>y;
	int t;
	cin>>t;
	vector<int> arr;
	vector<int> ary;
	for(int i=0; i<t; i++){
		int a,b;
		cin>>a>>b;
		if(a==0){
			arr.push_back(b);
		}
		else{
		ary.push_back(b);
	}}
	vector<int> x1(x);
	vector<int> y1(y);
	int cnt=1;
	for(int i=0; i<arr.size(); i++){
		for(int j=0; j<arr[i]; j++){
			y1[j]+=cnt;
		}
		cnt++;
		for(int j=arr[i]; j<y; j++){
			y1[j]+=cnt;
		}
		cnt++;
	}
	cnt=0;
	for(int i=0; i<ary.size(); i++){
		for(int j=0; j<ary[i]; j++){
			x1[j]+=cnt;
		}
		cnt++;
		for(int j=ary[i]; j<x; j++){
			x1[j]+=cnt;	
		}
		cnt++;
	}
	vector<int> save1(100001);
	vector<int> save2(100001);
	for(int i=0; i<x1.size(); i++){
		save1[x1[i]]++;
	}
	for(int i=0; i<y1.size(); i++){
		save2[y1[i]]++;
	}
	sort(save1.begin(),save1.end(),cmp);
	sort(save2.begin(),save2.end(),cmp);
	cout<<save1[0]*save2[0];
}