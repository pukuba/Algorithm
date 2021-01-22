#include <bits/stdc++.h>

using namespace std;
int a,x,y,b,d,e,c,f;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>a>>b>>c>>d>>e>>f;
    for(int i=-999; i<=999; i++){
        for(int j=-999; j<=999; j++){
            if(a*i + b*j == c && d*i + e*j == f){
                cout<<i<<' '<<j<<'\n';
                return 0;
            }
        }
    }
}