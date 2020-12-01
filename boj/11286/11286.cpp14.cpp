#include <bits/stdc++.h>

using namespace std;
struct P{
    int x;
    bool operator < (const P &a) const{
        if(abs(x) == abs(a.x)) return x>a.x;
        return abs(x) > abs(a.x);
    }
};
int t;
priority_queue<P> pq;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        if(k) pq.push({k});
        else{
            if(pq.size()){
                cout<<pq.top().x<<'\n';
                pq.pop();
            }
            else cout<<0<<'\n';
        }
    }
}