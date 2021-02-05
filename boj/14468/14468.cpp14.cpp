#include <bits/stdc++.h>

using namespace std;
string s;
int ans;
pair<int,int> a[30];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>s;
    for(int i=0; i<s.size(); i++){
        if(!a[s[i]-'A'].first) a[s[i]-'A'].first = i+1;
        else if(!a[s[i]-'A'].second) a[s[i]-'A'].second = i+1;
    }
    // i1 < j1 <i2 < j2
    for(int i=0; i<=25; i++){
        for(int j=0; j<=25; j++){
            if(a[i].first < a[j].first && a[j].first < a[i].second && a[i].second < a[j].second) ans++;
        }
    }
    cout<<ans;
}