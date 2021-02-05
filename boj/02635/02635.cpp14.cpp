#include <bits/stdc++.h>

using namespace std;
int n,cnt;
pair<int,int> _max;
vector<int> v[30001];
int ans(int a,int b){
    v[cnt].push_back(a);
    if(a-b<0){
        v[cnt].push_back(b);
        return 1;
    }
    return ans(b,a-b)+1;
}
int main(){
    cin>>n;
    for(int i=n; i>=1; i--){
        int save=ans(n,i)+1;
        if(_max.first<save){
            _max.first=save;
            _max.second=cnt;
        }
        cnt++;
    }
    cout<<_max.first<<'\n';
    for(int i=0; i<v[_max.second].size(); i++) cout<<v[_max.second][i]<<' ';
}
