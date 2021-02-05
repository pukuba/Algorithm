#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll arr[5111],ans[4],n,inf=1e10;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    ans[0]=inf;
    cin>>n;
    for(int i=1; i<=n; i++) cin>>arr[i];
    sort(arr+1,arr+n+1);
    for(int i=1; i<=n; i++){
        int left = i+1,right = n;
        while(left < right){
            ll temp = arr[left] + arr[i] + arr[right];
            if(llabs(temp) < ans[0]){
                ans[0]=llabs(temp);
                ans[1]=arr[left];
                ans[2]=arr[i];
                ans[3]=arr[right];
            }
            if(temp < 0) left++;
            else right--;
        }
    }
    sort(ans+1,ans+4);
    for(int i=1; i<4; i++) cout<<ans[i]<<' ';
}
