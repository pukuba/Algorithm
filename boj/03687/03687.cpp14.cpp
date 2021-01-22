#include <bits/stdc++.h>

using namespace std;
int t,cost[10]={6,2,5,5,4,5,6,3,7,6};
string d[104];
string maxx(int x){
    string s = "";
    if(~x&1) while(x) x-=2,s+='1';
    else{
        s+='7';
        while(x-3) s += '1',x-=2;
    }
    return s;
}

string cmp(string a,string b){
    if(a.size() == b.size()) return a < b ? a : b;
    if(a.size() < b.size()) return a;
    return b;
}

string minx(int x){
    d[0] = "";
    for(int i=0; i<=x; i++){
        for(int j=0; j<10; j++){
            if(i-cost[j]>=0){
                if(i-cost[j] == 0 && !j) continue;
                d[i] = cmp(d[i],d[i-cost[j]] + to_string(j));
            }
        }
    }
    return d[x];
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        fill(d,d+101,"9999999999999999999999999");
        cout<<minx(x)<<' '<<maxx(x)<<'\n';
    }
}