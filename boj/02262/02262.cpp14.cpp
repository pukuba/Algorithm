#include <bits/stdc++.h>

using namespace std;
int n,cnt;
vector<int> v;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1,x; i<=n; i++){
        cin>>x;
        v.push_back(x);
    }
    for(int i=1; i<n; i++){
        pair<int,int> info={0,1e9};
        vector<int> tmp;
        for(int j=0; j<v.size(); j++) if(info.first < v[j]) info = {v[j],j};
        for(int j=0; j<v.size(); j++){
            if(info.second == j){
                if(j == 0 || j == v.size()-1){
                    if(!j) cnt += abs(v[j]-v[j+1]),j++,tmp.push_back(min(v[j],v[j]+1));
                    else cnt += abs(v[j]-v[j-1]),tmp.pop_back(),tmp.push_back(min(v[j],v[j-1]));
                }
                else{
                    int l = abs(v[j]-v[j-1]),r = abs(v[j]-v[j+1]);
                    if(l < r) cnt += abs(v[j]-v[j-1]),tmp.pop_back(),tmp.push_back(min(v[j],v[j-1]));
                    else cnt += abs(v[j]-v[j+1]),tmp.push_back(min(v[j],v[j+1])),j++;
                }
            }
            else tmp.push_back(v[j]);
            //for(int k:tmp) cout<<k<<' ';
            //cout<<'\n';
        }
        v = tmp;
        //cout<<"---------\n";
        //cout<<'\n';
    }
    cout<<cnt<<'\n';
}
