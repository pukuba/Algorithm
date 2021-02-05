#include <bits/stdc++.h>

using namespace std;
priority_queue<int,vector<int>,greater<int>> pq;
int n,cnt;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        if(x) pq.push(x);
        if(!x){
            if(!pq.size()){
                cout<<'0'<<'\n';
            }
            else{
                cout<<pq.top()<<'\n';
                pq.pop();
            }
        }
    }
}
