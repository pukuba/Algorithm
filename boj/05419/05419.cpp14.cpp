#include <bits/stdc++.h>

using namespace std;
int t, a, b;
vector<pair<int,int>> p;
vector<int> q;
long long tree[75001];
int find_index(int a){
    int from = 0 , to = q.size() - 1;
    while(from <= to){
        int mid = (from+to)/2;
        //cout << mid << "\n";
        if(q[mid]==a ) return mid;
        if(q[mid]>=a) to = mid - 1;
        else if(q[mid]<a) from = mid + 1;
    }
    return -1;
}
void update(int idx,int value, long long _max){
    for(int i=idx; i<=_max; i+= (i& -i)) tree[i]+=value;
}
long long sum(int idx){
    long long ret = 0;
    for(int i=idx; i>0; i-=(i& -i)) ret += tree[i];
    return ret;
}
int main(){
    cin>>t;
    while(t--){
        memset(tree,false,sizeof(tree));
        p.clear(); q.clear();
        long long x,ans=0;
        cin>>x;
        for(int i= 0; i< x; i++){
            cin >> a >> b;
            p.push_back({a, b * -1});
            q.push_back(b * -1);
        }
        sort(q.begin(), q.end());
        sort(p.begin(), p.end());
        int idx = find_index(p[0].second) + 1;
        update(idx, 1,x);
        for(int i=1; i< x; i++){
            int _idx =find_index(p[i].second) + 1;
            ans += sum(_idx);
            update(_idx,1,x);
        }
        cout<<ans<<'\n';
    }
}
