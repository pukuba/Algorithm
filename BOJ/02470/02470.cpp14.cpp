#include <bits/stdc++.h>

using namespace std;
int n,x,inf=2e9+7,l,r,ans1,ans2;
vector<int> v;
int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        v.push_back(x);
    }
    r=v.size()-1;
    sort(v.begin(),v.end());
    while(1){
        if(inf > abs(v[l]+v[r])){
            ans1 = l;
            ans2 = r;
            inf = abs(v[l]+v[r]);
        }
        if(v[l]+v[r] > 0){
            if(l == r-1) break;
            r--;
        }
        else{
            if(l+1 == r) break;
            l++;
        }
    }
    cout<<v[ans1]<<' '<<v[ans2]<<'\n';
}