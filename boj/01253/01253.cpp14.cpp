#include <bits/stdc++.h>

using namespace std;
int n,arr[2020],ans;
bool binary(int x,int idx1,int idx2){ // 1 1
    int s = 1,e = n;
    while(s<=e){
        int mid = s + e >> 1;
        if(arr[mid] < x){
            s = mid + 1;
        }
        else if(arr[mid] > x){
            e = mid - 1;
        }
        else{
            if(mid != idx1 && mid != idx2) return true;
            int m1 = max(mid-1,1), m2 = min(mid+1,n);
            if(m1 != idx1 && m1 != idx2){
                if(x == arr[m1]) return true;
            }
            if(m2 != idx1 && m2 != idx2){
                if(x == arr[m2]) return true;
            }
            return false;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>arr[i];
    sort(arr+1,arr+1+n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(j == i) continue;
            if(binary(arr[i]-arr[j],i,j) == 1){
                ans++;
                break;
            }
        }
    }
    cout<<ans<<'\n';
}
