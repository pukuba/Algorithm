#include <bits/stdc++.h>

using namespace std;
int n,e,tmp;
vector<int> v;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1,x; i<=n; i++){
        cin>>x;
        if(e < x){
            e = x;
            v.push_back(tmp);
            tmp = 0;
        } else{
            tmp++;
        }
    }
    v.push_back(tmp);
    cout<<(*max_element(v.begin(),v.end()));
}