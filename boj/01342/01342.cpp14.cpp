#include <bits/stdc++.h>

using namespace std;
string s;
int n,a[10],ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>s;
    for(int i=0; i<s.size(); i++){
        a[i] = s[i] - 'a';
    }
    n = s.size();
    sort(a,a+n);
    do{
        bool flag = true;
        for(int i=0; i<n-1; i++){
            if(a[i] == a[i+1]){
                flag = false;
                break;
            }
        }
        if(flag) ans++;
    }while(next_permutation(a, a+n));
    cout<<ans<<'\n';
}
