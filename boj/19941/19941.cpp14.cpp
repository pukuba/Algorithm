#include <bits/stdc++.h>

using namespace std;
queue<int> q,p;
int n,k,ans;
string s;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k>>s;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'H') q.push(i);
        if(s[i] == 'P') p.push(i);
    }
    while(p.size()){
        int here = p.front();
        p.pop();
        while(q.size()){
            if(q.front() < here && here - q.front() > k) q.pop();
            else if(q.front() < here && here - q.front() <= k){
                ans++;
                q.pop();
                break;
            }
            else if(q.front() > here && q.front() - here > k) break;
            else if(q.front() > here && q.front() - here <= k){
                ans++;
                q.pop();
                break;
            }
        }
    }
    cout<<ans<<'\n';
}