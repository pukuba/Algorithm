#include <bits/stdc++.h>

using namespace std;
int a,b,c,cnt;
vector<int> v;
bool in(int x){
    for(int i=2; i<=128; i*=2) if(x == i) return 1;
    return 0;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>a>>b>>c;
    bool can = true;
    for(int i=-200; i<=200; i++){
        if(v.size() == 2) break;
        if(a*i*i+b*i+c == 0) v.push_back(i);
    }
    if(v.size() < 2) cout<<"둘다틀렸근";
    else if(in(v[0]) && in(v[1])) cout<<"이수근";
    else cout<<"정수근";
}