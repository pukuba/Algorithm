#include <bits/stdc++.h>

using namespace std;
int n,m[44][44],ans;
pair<int,int> p[22];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>p[1].first>>p[1].second;
    for(int i=2; i<=n; i++){
        cin>>p[i].first>>p[i].second;
        if(p[i-1].first == p[i].first){
            for(int j=min(p[i].second,p[i-1].second); j<=max(p[i].second,p[i-1].second); j++){
                m[p[i].first][j]=1;
            }
        }
        else{
            for(int j=min(p[i].first,p[i-1].first); j<=max(p[i].first,p[i-1].first); j++){
                m[j][p[i].second]=1;
            }
        }
    }
    if(p[1].first == p[n].first){
        for(int i=min(p[1].second,p[n].second); i<=max(p[1].second,p[n].second); i++){
            m[p[1].first][i]=1;
        }
    }
    else{
        for(int j=min(p[1].first,p[n].first); j<=max(p[1].first,p[n].first); j++){
            m[j][p[1].second]=1;
        }
    }
    for(int i=0; i<=40; i++){
        for(int j=0; j<=40; j++) ans+=m[i][j];
    }
    cout<<ans;
}