#include <bits/stdc++.h>

using namespace std;
int n,m;
vector<vector<int> > v;
vector<int> temp;
void f(int here){
    if(here == n){
        v.push_back(temp);
        return;
    }
    if(here >= n) return;
    for(int i=1; i<=3; i++){
        temp.push_back(i);
        f(here+i);
        temp.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m;
    f(0);
    if(m > v.size()){
        cout<<-1;
        return 0;
    }
    for(int i=0; i<v[m-1].size(); i++){
        cout<<v[m-1][i];
        if(i!=v[m-1].size()-1) cout<<"+";
    }
}