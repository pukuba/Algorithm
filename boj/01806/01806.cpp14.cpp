#include <bits/stdc++.h>

using namespace std;
int n,m,ans=1e9,arr[100004],from=0,to=0,temp=0;
int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>arr[i];
    temp=arr[0];
    while(from<=to && to <n){
        if(temp < m) temp += arr[++to];
        else if(temp == m){
            ans = min(ans,(to-from)+1);
            temp -= arr[from++];
        }
        else if(temp > m){
            ans = min(ans,(to-from)+1);
            temp -= arr[from++];
        }
    }
    if(ans == 1e9) cout<<0;
    else cout<<ans;
}
