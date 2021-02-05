#include <bits/stdc++.h>

using namespace std;
int n,x[11],ans;
int cal(int a,int b,int c,int d){
    int ax=1, bx=1, cx=1, dx=1;
    for(int i=1; i<=a; i++) ax*=x[i];
    for(int i=a+1; i<=a+b; i++) bx*=x[i];
    for(int i=a+b+1; i<=a+b+c; i++) cx*=x[i];
    for(int i=a+1+b+c; i<=n; i++) dx*=x[i];
    return ax+bx+cx+dx;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>x[i];
    for(int a=1; a<=n-3; a++){
        for(int b=1; b<=n-3; b++){
            for(int c=1; c<=n-3; c++){
                for(int d=1; d<=n-3; d++){
                    if(a+b+c+d == n){
                        ans = max(ans,cal(a,b,c,d));
                    }
                }
            }
        }
    }
    cout<<ans<<'\n';
}
