#include <bits/stdc++.h>

using namespace std;
int cnt,n,x;
int gcd(int a,int b){return b ? gcd(b,a%b) : a;}
int main(){
    cin>>n>>x;
    vector<int> v(n);
    for(int &i:v) cin>>i;
    v.push_back(x);
    sort(v.begin(),v.end());
    cnt = abs(v[0]-v[1]);
    for(int i=0; i<v.size()-1; i++){
        cnt = min(cnt, gcd(abs(v[i]-v[i+1]),cnt));
    }
    cout<<cnt<<'\n';
}