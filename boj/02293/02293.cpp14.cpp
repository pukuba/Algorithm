#include <bits/stdc++.h>

using namespace std;
int d[10001];
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a;
    int cnt=0;
    d[0]=1;
    while(n--){
        int x;
        cin>>x;
        a.push_back(x);
    }
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j <= m; j++){
            if(j - a[i] >= 0) d[j] += d[j - a[i]];
        }
    }
    
//    for(int i=0; i<10001; i++){
//        for(int j=0; j<a.size(); j++){
//            if(i-a[j]>=0) d[i]+=d[i-a[j]];
//        }
//    }
    cout<<d[m]<<'\n';
}
