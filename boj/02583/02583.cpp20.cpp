#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n,m,k,dy[4]={0,1,0,-1},dx[4]={1,0,-1,0};
bool check[105][105];
vector<int> v;
bool in(int a,int b){return 0<=a && a<n && 0<=b && b<m;}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>m>>n>>k;
    for(int i=0; i<k; i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        for(int i=x1; i<x2; i++){
            for(int j=y1; j<y2; j++) check[i][j] = 1;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!check[i][j]){
                queue<pair<int,int> > q;
                int ans = 1;
                q.push({i,j});
                check[i][j] = 1;
                while(q.size()){
                    int y = q.front().first, x = q.front().second;
                    q.pop();
                    for(int k=0; k<4; k++){
                        int ny = y + dy[k], nx = x + dx[k];
                        if(in(ny,nx) && !check[ny][nx]){
                            check[ny][nx] = 1;
                            q.push({ny,nx});
                            ans++;
                        }
                    }
                }
                v.push_back(ans);
            }
        }
    }
    sort(v.begin(),v.end());
    cout<<v.size()<<'\n';
    for(int i : v) cout<<i<<' ';
}
