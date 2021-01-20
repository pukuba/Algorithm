#include <bits/stdc++.h>

using namespace std;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> >> pq;
int t;
int main(){
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        if(!x){
            if(pq.empty()) cout<<"0"<<'\n';
            else{
                cout<<pq.top().second<<'\n';
                pq.pop();
            }
        }
        if(x) pq.push({abs(x),x});
    }
}
