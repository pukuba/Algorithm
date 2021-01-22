#include <bits/stdc++.h>

using namespace std;
int n,m,k;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1; i<=k; i++){
        m++;
        if(m>=60){
            m-=60;
            n++;
        }
        if(n>=24) n-=24;
    }
    cout<<n<<' '<<m;
}