#include <bits/stdc++.h>

using namespace std;
int n,t,p,ans,arr[100111],cnt,ret;
priority_queue<int,vector<int>,less<>> pq;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>t>>p;
    for(int i=1; i<=n; i++) cin>>arr[i];
    for(int i=1; i<=n; i++){
        ans += arr[i];
        pq.push(arr[i]);
        cnt++;
        if(p*(i-1) > t) break;
        while(p * (i-1) + ans > t){
            cnt--;
            ans -= pq.top();
            pq.pop();
        }
        ret = max(ret,cnt);
    }
    cout<<ret;
}
