#include <bits/stdc++.h>

using namespace std;
string s;
int a[55],cnt,where=-1;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>s;
    sort(s.begin(),s.end());
    for(char c : s) a[c-'A']++;
    for(int i=0; i<=26; i++) if(a[i]&1) cnt++,where=i;
    if(cnt>1) cout<<"I'm Sorry Hansoo\n";
    else{
        string b;
        if(where != -1){
            b += char(where+'A');
            a[where]--;
        }
        for(int i=0; i<=26; i++){
            if(a[i]){
                for(int j=1; j<=a[i]/2; j++) cout<<char(i+'A');
                a[i]/=2;
            }
        }
        cout<<b;
        for(int i=26; i>=0; i--) if(a[i]) for(int j=1; j<=a[i]; j++) cout<<char(i+'A');
        cout<<'\n';
    }
}