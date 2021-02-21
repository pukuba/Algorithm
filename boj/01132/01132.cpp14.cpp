#include <bits/stdc++.h>
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;
int n,v[10];
string s[51];
ll ans,a[15][15];
set<int> st;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=0; i<=9; i++) v[i] = i;
    for(int i=1; i<=n; i++) cin>>s[i];
    for(int i=1; i<=n; i++){
        st.insert(s[i].front()-'A');
        for(int j=s[i].size()-1,k=0; j>=0; j--,k++){
            a[s[i][j]-'A'][11-k]++; //a[알파벳][길이]
        }
    }
    //9876543213 나
    //9876540327 정답
    do{
        ll temp = 0;
        bool flag = 1;
        for(int i : st){
            if(v[i] == 0) flag = 0;
        }
        if(flag) for(int i=0; i<10; i++){
            for(ll j=0,k=1e11; j<12; j++,k/=10){
                temp += a[i][j] * k * v[i];
            }
        }
        
        ans = ans > temp ? ans : temp;
    }while(next_permutation(v, v + 10));
    cout<<ans<<'\n';
}
