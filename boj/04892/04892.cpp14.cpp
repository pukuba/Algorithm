#include <bits/stdc++.h>

using namespace std;
int x,t;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    while(1){
        t++;
        cin>>x;
        if(!x) return 0;
        int n2 = 0, n3 = 0, n4 = 0;
        if((x*3)&1) n2 = (x*3+1)>>1;
        else n2 = (x*3)>>1;
        n3 = 3 * n2;
        n4 = n3/9;
        cout<<t<<'.'<<' '<<(((x*3)&1)?"odd":"even")<<' '<<n4<<'\n';
    }
}