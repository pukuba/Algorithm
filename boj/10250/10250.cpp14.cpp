#include <bits/stdc++.h>

using namespace std;
int n;
int main(){
    cin>>n;
    while(n--){
        int a,b,c,cnt=0,x,y;
        cin>>a>>b>>c;
        for(int i=1; i<=b; i++){
            for(int j=1; j<=a; j++){
                cnt++;
                if(cnt==c){
                    x=j,y=i;
                }
            }
        }
        if(y>9) cout<<x<<y<<'\n';
        else cout<<x<<0<<y<<'\n';
    }
}
