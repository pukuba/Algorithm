#include <bits/stdc++.h>

using namespace std;
int t;
bool prime[5000003];
long long a,b;
set<int> st1,st2;
priority_queue<int,vector<int>, greater<int>> pq1,pq2;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    prime[0] = prime[1] = 1;
    for(int i=2; i*i<=5000000; i++){
        if(!prime[i]){
            for(int j=i+i; j<=5000000; j+=i){
                prime[j] = true;
            }
        }
    }
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        if(!prime[x]){
            if(st1.count(x) || st2.count(x)) a -= 1000;
            else{
                st1.insert(x);
                pq1.push(x);
                if(pq1.size() >= 4) pq1.pop();
            }
        }
        else if(prime[x]){
            if(pq2.size() <= 2) b += 1000;
            else b += pq2.top();
        }
        if(!prime[y]){
            if(st1.count(y) || st2.count(y)) b -= 1000;
            else{
                st2.insert(y);
                pq2.push(y);
                if(pq2.size() >= 4) pq2.pop();
            }
        }
        else if(prime[y]){
            if(pq1.size() <= 2) a += 1000;
            else a += pq1.top();
        }
    }
    if(a == b) cout<<"우열을 가릴 수 없음";
    else if(a > b) cout<<"소수의 신 갓대웅";
    else cout<<"소수 마스터 갓규성";
}