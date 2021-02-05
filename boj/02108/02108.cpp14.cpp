#include <bits/stdc++.h>

using namespace std;
int n,a1,ans;
double sum;
vector<int> v,a2;
map<int,int> m;
set<int> s;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    v.resize(n);
    for(int&x:v){
        cin>>x;
        sum += x;
        m[x]++;
        if(a1 <= m[x]){
            a1 = m[x];
        }
        s.insert(x);
    }
    for(int i : s){
        if(m[i] == a1){
            a2.push_back(i);
        }
    }
    sum/=n;
    sum = round(sum);
    ans = sum;
    sort(v.begin(),v.end());
    sort(a2.begin(),a2.end());
    a1 = (a2.size() == 1 ? a2.front() : a2[1]);
    cout<<ans<<'\n'<<v[n/2]<<'\n'<<a1<<'\n'<<v[n-1]-v[0]<<'\n';
}
