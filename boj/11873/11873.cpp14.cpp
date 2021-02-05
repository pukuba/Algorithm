#include <bits/stdc++.h>

using namespace std;
int n,m,height[1003][1003],ans;
bool _map[1003][1003];
int divi(int s,int e,int h){
    if(s+1 == e) return height[h][s];
    int mid = s+e>>1,ret = max(divi(s,mid,h),divi(mid,e,h));
    int l = mid,r = mid,he = height[h][mid],w = 1;
    while(r-l+1 < e-s){
        int left_go = -1,right_go = -1;
        if(s<l) left_go = min(he,height[h][l-1]);
        if(r<e-1) right_go = min(he,height[h][r+1]);
        if(left_go >= right_go){
            l--;
            he = left_go;
        }
        else{
            r++;
            he = right_go;
        }
        ret = max(ret,++w*he);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    while(1){
        ans = 0;
        cin>>n>>m;
        memset(_map,false,sizeof(_map));
        memset(height,false,sizeof(height));
        if(n == 0 && m == 0) return 0;
        for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
            cin>>_map[i][j];
            if(_map[i][j]) height[i][j] = height[i-1][j]+1;
        }
        for(int i=1; i<=n; i++) ans = max(ans,divi(1,m+1,i));
        cout<<ans<<'\n';
    }
}