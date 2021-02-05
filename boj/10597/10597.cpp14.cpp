#include <bits/stdc++.h>

using namespace std;
string s;
int arr[11];
bool check[51];
vector<int> ans;
stack<int> q,q1;
void dfs(int idx){
    if(idx == s.size()){
        while(!q.empty()){
            q1.push(q.top());
            q.pop();
        }
        while(q1.size()){
            cout<<q1.top()<<' ';
            q1.pop();
        }
        exit(0);
    }
    for(int i : ans){
        if(check[i]) continue;
        if(i > 9 && s[idx]-'0' == i/10 && s[idx+1]-'0' == i%10){
            q.push(i);
            check[i] = true;
            dfs(idx+2);
            check[i] = false;
            q.pop();
        }
        if(i < 10 && s[idx]-'0' == i){
            q.push(i);
            check[i] = true;
            dfs(idx+1);
            check[i] = false;
            q.pop();
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>s;
    for(char i : s) arr[i-'0']++;
    memset(check,false,sizeof(check));
    for(int i=1; i<=50; i++){
        int temp = i;
        bool can = false;
        while(temp > 0){
            if(arr[temp%10] > 0){
                arr[temp%10]--;
                can = true;
            }
            temp/=10;
        }
        if(!can) break;
        ans.push_back(i);
    }dfs(0);
}