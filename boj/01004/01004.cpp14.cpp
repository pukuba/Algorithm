#include <bits/stdc++.h>

using namespace std;
#define y1 fuck
int x1,x2,y1,y2;
bool check(int a,int b,int c){
    double dis1=sqrt(pow(x1-a,2)+pow(y1-b,2));
    double dis2=sqrt(pow(y2-b,2)+pow(x2-a,2));
    if(dis2-c > 0 && dis1-c < 0){
        return true;
    }
    if(dis1-c >0 && dis2-c < 0){
        return true;
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>x1>>y1>>x2>>y2;
        int n,ans=0;
        cin>>n;
        for(int i=0; i<n; i++){
            int cx,cy,r;
            cin>>cx>>cy>>r;
            if(check(cx,cy,r)) ans++;
        }
        cout<<ans<<'\n';
    }
}
