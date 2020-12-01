#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> a;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    for(int i=0; i<a.size(); i++){
         cout<<a[i]<<'\n';  
    }
}
