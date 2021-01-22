#include <bits/stdc++.h>

using namespace std;
int a[11],b[11],x,y,win=0;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    for(int i=1; i<=10; i++) cin>>a[i];
    for(int i=1; i<=10; i++) cin>>b[i];
    for(int i=1; i<=10; i++){
        if(a[i] > b[i]) x+=3,win = 1;
        if(a[i] < b[i]) y+=3,win = 2;
        if(a[i] == b[i]) x++,y++;
    }
    cout<<x<<' '<<y<<'\n';
    if(x == y){
        if(win == 1) cout<<'A';
        else if(win == 2) cout<<'B';
        else cout<<'D';
    }
    else cout<<(x>y ? 'A':'B');
}