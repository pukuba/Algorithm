#include <bits/stdc++.h>

using namespace std;
char c[20];
vector<string> ans;
int n;
bool check[10];
bool ok(string str){
    for(int i=0; i<n; i++){
        if(c[i]=='>'){
            if(str[i]<str[i+1]) return false;
        }
        else if(c[i]=='<'){
            if(str[i]>str[i+1]) return false;
        }
    }
    return true;
}
void go(int i,string k){
    if(i==n+1){
        if(ok(k)){
            ans.push_back(k);
        }
        return;
    }
    for(int j=0; j<=9; j++){
        if(check[j]) continue;
        check[j]=true;
        go(i+1,k+to_string(j));
        check[j]=false;
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        cin>>c[i];
    }
    go(0,"");
    sort(ans.begin(),ans.end());
    cout<<ans[ans.size()-1]<<'\n'<<ans[0]<<'\n';
}
