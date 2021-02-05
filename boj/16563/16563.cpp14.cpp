#include <bits/stdc++.h>

using namespace std;
vector<int> prime;
bool check[5050505];
int n;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=2; i*i<=5000000; i++){
        if(!check[i]){
            for(int j=i+i; j<=5000000; j+=i) check[j] = 1;
        }
    }
    for(int i=2; i<=5000000; i++) if(!check[i]) prime.push_back(i);
    for(int i=1,x; i<=n; i++){
        cin>>x;
        while(x != 1){
            if(!check[x]){
                cout<<x<<'\n';
                break;
            }
            for(int i=0; i<prime.size(); i++){
                if(!(x%prime[i])){
                    x /= prime[i];
                    cout<<prime[i]<<' ';
                    break;
                }
            }
        }
    }
}
