#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <tuple> 

using namespace std;
struct Stu{
	string name;
	int kor,eng,math;
};

bool cmp(const Stu &u,const Stu &v){
	return make_tuple(-u.kor,u.eng,-u.math,u.name)<make_tuple(-v.kor,v.eng,-v.math,v.name);
}
int main(){
	int n;
	cin>>n;
	vector<Stu> a(n);
	for(int i=0; i<n; i++){
		cin>>a[i].name>>a[i].kor>>a[i].eng>>a[i].math;
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=0; i<n; i++){
		cout<<a[i].name<<'\n';
	}
} 