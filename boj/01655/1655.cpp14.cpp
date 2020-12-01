#include <bits/stdc++.h>

using namespace std;
int n,x;
priority_queue<int,vector<int>> maxh;
priority_queue<int,vector<int>,greater<>> minh;
//6 5 4 min max 3 2 1
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>x;
        if(i&1) maxh.push(x);
        else minh.push(x);
        if(i>=2){
            if(maxh.top() > minh.top()){
                int cmax = maxh.top();maxh.pop();
                int cmin = minh.top();minh.pop();
                maxh.push(cmin),minh.push(cmax);
            }
        }
        cout<<maxh.top()<<'\n';
    }
}