#include <bits/stdc++.h>

using namespace std;
int n,d[1001];
int main(){
    cin>>n;
    if(n==1000){
        cout<<"144";
        return 0;
    }
    for(int i=0; i<=99; i++){
        d[i]=i;
    }
    for(int i=100; i<1000; i++){
        bool check=false;
        string s=to_string(i);
        int ai[3],keep=i;
        ai[0]=keep%10;
        keep/=10;
        ai[1]=keep%10;
        keep/=10;
        ai[2]=keep%10;
        int same=abs(i%10-(i/10)%10);
        if(ai[2]+same==ai[1] && ai[2]+same*2==ai[0]) check=true;
        else if(ai[0]+same==ai[1] && ai[0]+same*2==ai[2]) check=true;
        if(check) d[i]=d[i-1]+1;
        else d[i]=d[i-1];
    }
    cout<<d[n];
}
