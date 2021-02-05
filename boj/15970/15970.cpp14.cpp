#include <bits/stdc++.h>

using namespace std;
vector<int> v[5001];
int n,ans;
int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        int a,b;
        cin>>a>>b;
        v[b].push_back(a);
    }
    for(int i=1; i<=n; i++) sort(v[i].begin(),v[i].end());
    for(int i=1; i<=5000; i++){
        for(int j=0; j<v[i].size(); j++){
            if(j == 0 && v[i].size() > 1) ans+= abs(v[i][j]-v[i][j+1]);
            else if(j == v[i].size()-1 && v[i].size()-1) ans+= abs(v[i][j] - v[i][j-1]);
            else{
                int check1 = abs(v[i][j]-v[i][j-1]);
                int check2 = abs(v[i][j]-v[i][j+1]);
                if(check1 > check2) ans+=check2;
                else ans+=check1;
            }
        }
    }
    cout<<ans<<'\n';
}
