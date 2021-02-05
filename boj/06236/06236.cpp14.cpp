#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,m,arr[100004],start;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        start = max(start,arr[i]);
    }
    ll high = 1000000000,low = start;
    while(low < high){
        ll mid = low + high >> 1,temp = 0,cnt = 1;
        for(int i=1; i<=n; i++){
            if(temp + arr[i]> mid){
                temp = arr[i];
                cnt++;
            }
            else temp += arr[i];
        }
        if(cnt > m) low = mid+1;
        else high = mid;
    }
    cout<<low<<'\n';
}