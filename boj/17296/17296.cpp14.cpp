#include <bits/stdc++.h>

using namespace std;
double arr[1003];
int n,ans;
bool jump = false;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>arr[i];
    for(int i=1; i<=n; i++){
        if(arr[i] >= 0.49 && !jump){
            jump = true;
            ans++;
            arr[i]-=1;
            while(arr[i] >= 0.1){
                arr[i]-=1;
                ans++;
            }
        }
        else if(arr[i] >= 0.49 && jump){
            arr[i]-=0.5;
            while(arr[i] >= 0.1){
                arr[i]-=1;
                ans++;
                jump=true;
            }
        }
    }
    cout<<ans;
}