#include <bits/stdc++.h>

using namespace std;
vector<string> v;
int ans=1e9,n,A[5];
struct P{int a,b,c,d,e;}D[30];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>A[1]>>A[2]>>A[3]>>A[4];
    for(int i=1; i<=n; i++) cin>>D[i].a>>D[i].b>>D[i].c>>D[i].d>>D[i].e;
    for(int i=0; i<(1<<16); i++){
        int x=0,y=0,z=0,xx=0,yy=0;
        for(int j=0; j<=14; j++){
            if(i&(1<<j)){
                x += D[j+1].a;
                y += D[j+1].b;
                z += D[j+1].c;
                xx += D[j+1].d;
                yy += D[j+1].e;
            }
        }
        if(A[1] <= x && A[2] <= y && A[3] <= z && A[4] <= xx && ans >= yy) ans = yy;
    }
    for(int i=0; i<(1<<16); i++){
        int x=0,y=0,z=0,xx=0,yy=0;
        string s = "";
        for(int j=0; j<=14; j++){
            if(i&(1<<j)){
                x += D[j+1].a;
                y += D[j+1].b;
                z += D[j+1].c;
                xx += D[j+1].d;
                yy += D[j+1].e;
                s += to_string(j+1) + " ";
            }
        }
        if(A[1] <= x && A[2] <= y && A[3] <= z && A[4] <= xx && ans == yy) v.push_back(s);
    }
    if(ans == 1e9){
        cout<<-1<<'\n';
        return 0;
    }
    cout<<ans<<'\n';
    sort(v.begin(),v.end());
    for(char c : v[0]){
        if(c != ' ')cout<<c;
        else cout<<' ';
    }
}