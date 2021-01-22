#include <bits/stdc++.h>

using namespace std;
int n,m,a[1010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    if(((m+1)*m)/2 > n) cout<<-1;
    else{
        for(int i=1; i<=m; i++){
            a[i] += i;
            n-=i;
        }
        int e = m;
        while(n--){
            if(e == 0) e = m;
            a[e]++;
            e--;
        }
        cout<<a[m]-a[1]<<'\n';
    }
}