#include <bits/stdc++.h>

using namespace std;
int d[10001];
int main(){
    d[0]=1;
    for(int i=1; i<=3; i++){
            for(int f=i; f<=10000; f++){
                d[f]+=d[f-i];
            }
    }
    int a;
    cin>>a;
    while(a--){
        int n;
        cin>>n;
        cout<<d[n]<<'\n';
    }
}

