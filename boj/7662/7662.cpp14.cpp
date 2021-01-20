#include <bits/stdc++.h>

using namespace std;
multiset<int> _set;
int n,x;
vector<int> v;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    while(n--){
        int t;
        cin>>t;
        while(t--){
            char c;
            int a;
            cin>>c>>a;
            if(c=='I') _set.insert(a);
            if(c=='D' && !_set.empty()){
                auto it = _set.end(); it--;
                if(a==-1) _set.erase(_set.begin());
                if(a==1) _set.erase(it);
            }
        }
        if(_set.empty()) cout<<"EMPTY\n";
        else{
            auto it = _set.end(); it--;
            cout<<(*it)<<' ';
            cout<<(*_set.begin())<<'\n';
        }
        _set.clear();
    }
}
