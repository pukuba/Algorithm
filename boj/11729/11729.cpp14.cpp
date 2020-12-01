#include <bits/stdc++.h>

using namespace std;
int n;
queue<pair<int,int> > q;
void f(int h,int from,int to,int go){
    if(h == 1) q.push({from,to});
    else{
        f(h-1,from,go,to);
        q.push({from,to});
        f(h-1,go,to,from);
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    f(n,1,3,2);
    cout<<q.size()<<'\n';
    while(q.size()){
        cout<<q.front().first<<' '<<q.front().second<<'\n';
        q.pop();
    }
}