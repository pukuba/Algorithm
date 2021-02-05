#include <bits/stdc++.h>

using namespace std;
int n,ans;
vector<int> v;
set<vector<int> > comb;
int check(vector<int> vec){
    int ret = 0;
    for(vector<int> i : comb){
        int sum = 0;
        for(int j : i){
            sum += v[j];
        }
        if(sum == 50) ret++;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    v.resize(n);
    for(int i=0; i<n; i++){
        vector<int> tmp;
        for(int j=i; j<n; j++){
            tmp.push_back(j);
            vector<int> test;
            for(int k=0; k<n; k++){
                if(i<=k && k<=j) continue;
                test.push_back(k);
            }
            if(!comb.count(tmp) && !comb.count(test)){
                comb.insert(tmp);
            }
        }
    }
    for(int&x:v) cin>>x;
    sort(v.begin(),v.end());
    do{
        ans = max(ans, check(v));
    }while(next_permutation(v.begin(), v.end()));
    cout<<ans;
}
