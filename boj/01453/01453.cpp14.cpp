#include <bits/stdc++.h>

using namespace std;
int n,arr[101],ans;
int main(){
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        if(!arr[x]){
            arr[x]++;
        }
        else ans++;
    }
    cout<<ans<<'\n';
}
