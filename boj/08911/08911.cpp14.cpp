#include <bits/stdc++.h>
#define y1 fuckkkkk
using namespace std;
int t,y,x,yt,yb,xl,xr,l,dy[4]={-1,0,1,0},dx[4]={0,1,0,-1}; //상우하좌
string s;
void update(){yt = max(yt,y);yb = min(yb,y);xr = max(xr,x); xl = min(xl,x);}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>t;
    while(t--){
        cin>>s;
        yt = yb = xl = xr = l = y = x = 0;
        for(char c : s){
            if(c == 'F') y += dy[l], x+= dx[l],update();
            if(c == 'B') y -= dy[l], x-= dx[l],update();
            if(c == 'L'){l--; if(l<0) l=3;}
            if(c == 'R'){l++; if(l>3) l=0;}
        }
        yb *= -1;
        xl *= -1;
        cout<<(yb + yt) * (xr + xl)<<'\n';
    }
}