#include <bits/stdc++.h>

using namespace std;
map<string,string> table;
vector<string> v;
int t,n;
int main(){
    cin>>t;
    while(t--){
        v.clear();
        table.clear();
        cin>>n;
        for(int i=1; i<=n; i++){
            string s1,s2;
            cin>>s1>>s2;
            v.push_back(s2);
            table[s2]+="/"+s1;
        }
        for(int i=0; i<v.size(); i++){
            if(v[i]!="@@"){
                for(int j=i+1; j<v.size(); j++){
                    if(v[i]==v[j]) v[j]="@@";
                }
            }
        }
        int ans[1001];
        memset(ans,false,sizeof(ans));
        int cnt=0;
        int cross=1;
        for(int i=0; i<v.size(); i++){
            if(v[i]!="@@"){
                for(int j=0; j<table[v[i]].size(); j++){
                    if(table[v[i]][j]=='/'){
                        ans[i]++;
                        cnt++;
                    }
                }
            }
            //부위가담김
        }
        int check=0;
        for(int i=0; i<1001; i++){
            if(ans[i]!=0) cross*=(ans[i]+1),check++;
        }
        if(check<2) cross=0;
        if(cross==0) cout<<cnt<<'\n';
        else cout<<cross-1<<'\n';
    }
}
