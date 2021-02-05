#include <bits/stdc++.h>

using namespace std;
bool check[4000001];
vector<int> prime;
int n,from,to,temp,ans;
int main(){
    check[0]=check[1]=true;
    for(int i=2; i*i<=4000000; i++) if(!check[i]) for(int j=i+i; j<=4000000; j+=i) check[j]=true;
    for(int i=2; i<=4000000; i++) if(!check[i]) prime.push_back(i);
    cin>>n;
    while(to!=prime.size() && from!=prime.size()){
        if(temp < n){
            temp += prime[to];
            to++;
        }
        if(temp == n){
            ans++;
            temp -= prime[from];
            from++;
        }
        if(temp > n){
            temp -= prime[from];
            from++;
        }
    }
    cout<<ans<<'\n';
}
