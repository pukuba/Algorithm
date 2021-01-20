#include <bits/stdc++.h>

using namespace std;
int a,b,c;
long long cal(int a,int b){
    if(b==0) return 0;
    if(b==1) return a;
    if(b%2) return cal(a,b-1)*a;
    long long ret = cal(a,b/2)%c;
    return (ret*ret)%c;
}
int main(){
    cin>>a>>b>>c;
    cout<<cal(a,b)%c;
}
