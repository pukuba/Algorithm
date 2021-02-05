#include <bits/stdc++.h>

using namespace std;
bool check[4444444];
int n;
vector<int> prime;
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    check[0]=check[1]=true;
    for(int i=2; i*i<=1000000; i++){
        if(!check[i]){
            for(int j=i+i; j<=1000000; j+=i){
                check[j]=true;
            }
        }
    }
    for(int i=2; i<=1000000; i++) if(!check[i]) prime.push_back(i);
    for(int i=0; i<prime.size(); i++){
        for(int j=i; j<prime.size(); j++){
            int h_number = n-(prime[i]+prime[j]);
            if(h_number < 0 ) break;
            for(int k=j; k<prime.size(); k++){
                if(prime[k]>h_number) break;
                if(prime[k]<h_number){
                    int last_prime = h_number - prime[k];
                    if(!check[last_prime]){
                        cout<<prime[i]<<' '<<prime[j]<<' '<<prime[k]<<' '<<last_prime<<'\n';
                        return 0;
                    }
                }
            }
        }
    }
    cout<<-1<<'\n';
}
