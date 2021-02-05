#include <bits/stdc++.h>

using namespace std;
int n,m,ans=-1;
bool check[12][1000005];
int change(string s,int fir_idx,int sec_idx){
    if(s[0]=='0') return -1;
    char c=s[fir_idx];
    s[fir_idx]=s[sec_idx];
    s[sec_idx]=c;
    if(s[0]=='0') return -1;
    int ret = atoi(s.c_str());
    return ret;
}
int main(){
    cin>>n>>m;
    queue<pair<int,int> >  q;
    q.push({n,0});
    while(!q.empty()){
        int cur_number = q.front().first;
        int cur_cnt = q.front().second;
        q.pop();
        if(cur_cnt == m){
            ans = max(ans,cur_number);
            continue;
        }
        string s = to_string(cur_number);
        for(int i=0; i<s.size(); i++){
            for(int j=i+1; j<s.size(); j++){
                if(change(s,i,j)!=-1 && !check[cur_cnt+1][change(s,i,j)]){
                    check[cur_cnt+1][change(s,i,j)]=true;
                    q.push({change(s,i,j),cur_cnt+1});
                }
            }
        }
    }
    cout<<ans<<'\n';
}
