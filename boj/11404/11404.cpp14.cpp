#include <bits/stdc++.h>

using namespace std;
int v,e,dist[111][111];
const int inf = 1e9;
int main(){
    cin>>v>>e;
    for(int i=1; i<=v; i++) for(int j=1; j<=v; j++) dist[i][j] = (i==j)?0:inf;
    for(int i=1; i<=e; i++){
        int a,b,c;
        cin>>a>>b>>c;
        dist[a][b]=min(dist[a][b],c);
    }
    for(int k=1; k<=v; k++) for(int i=1; i<=v; i++) for(int j=1; j<=v; j++) dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    for(int i=1; i<=v; i++){
        for(int j=1; j<=v; j++){
            if(dist[i][j]==inf) dist[i][j]=0;
            cout<<dist[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
