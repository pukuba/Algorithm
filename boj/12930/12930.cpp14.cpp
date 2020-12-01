#include <bits/stdc++.h>

using namespace std;
using t = tuple<int,int,int,int>;
priority_queue<t,vector<t>,greater<>> pq;
bool check[22];
int n,dist[22][22][3],d[22];
vector<int> v[22];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    memset(d,-1,sizeof(d));
    cin>>n;
    for(int i=1; i<=2; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                char c;
                cin>>c;
                if(c == '.') continue;
                dist[j][k][i] = c-'0';
                v[j].push_back(k);
                v[k].push_back(j);
            }
        }
    }
    pq.push({0,1,0,0});
    while(!pq.empty()){
        auto[weight,here,w1,w2] = pq.top();
        pq.pop();
        if(check[here]) continue;
        check[here] = true;
        for(int i : v[here]){
            int next_w1 = dist[here][i][1] + w1;
            int next_w2 = dist[here][i][2] + w2;
            if(d[i] > next_w1 * next_w2 || d[i] == -1){
                d[i] = next_w1 * next_w2;
                pq.push({next_w1 * next_w2,i,next_w1,next_w2});
            }
        }
    }
    cout<<d[2];
}
