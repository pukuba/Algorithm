#include <bits/stdc++.h>

using namespace std;
int cal(vector<int> &v){
    int sum=0;
    for(int i=0; i<v.size()-1; i++){
        sum+=abs(v[i]-v[i+1]);
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    int ans=0;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    do{
        int temp=cal(a);
        ans=max(temp,ans);
    }while(next_permutation(a.begin(), a.end()));
    cout<<ans<<'\n';
}
