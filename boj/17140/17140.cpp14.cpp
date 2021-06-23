#include <bits/stdc++.h>

using namespace std;
int r,c,k,a[105][105],ll,rr;
void p(int x){cout<<x;exit(0);}
bool cal(){
    int i=0,j=0;
    for(int x=1; x<=100; x++){
        for(int y=1; y<=100; y++){
            if(a[y][x]){
                j = max(j,y);
                i = max(i,x);
            }
        }
    }
    return j>=i; // true R ? C
}
void doit(int t){
    if(t > 100) p(-1);
    if(a[r][c] == k) p(t);
    bool go = cal();
    int lidx = 0;
    if(go){
        for(int i=1; i<=100; i++){
            map<int,int> mp;
            for(int j=1; j<=100; j++){
                if(!a[i][j]) continue;
                mp[a[i][j]]++;
            }
            int idx = 1;
            vector<pair<int,int> > v;
            for(pair<int,int> pi : mp) v.push_back({pi.second,pi.first});
            sort(v.begin(),v.end());
            for(int j=0; j<v.size(); j++){
                if(idx > 100) break;
                a[i][idx++] = v[j].second;
                a[i][idx++] = v[j].first;
            }
            for(int j=idx; j<=100; j++) a[i][j] = 0;
        }
    } else {
        for(int i=1; i<=100; i++){
            map<int,int> mp;
            for(int j=1; j<=100; j++){
                if(!a[j][i]) continue;
                mp[a[j][i]]++;
            }
            vector<pair<int,int> > v;
            int idx = 1;
            for(pair<int,int> pi : mp) v.push_back({pi.second,pi.first});
            sort(v.begin(),v.end());
            for(int j=0; j<v.size(); j++){
                if(idx > 100) break;
                a[idx++][i] = v[j].second;
                a[idx++][i] = v[j].first;
            }
            for(int j=idx; j<=100; j++) a[j][i] = 0;
        }
    }
    doit(t+1);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>r>>c>>k;
    for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++){
            cin>>a[i][j];
        }
    }
    doit(0);
}