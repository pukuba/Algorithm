#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll d[41]={0,5,13},n;
string messi = "Messi Gimossi";
int main(){
    cin>>n;n--;
    for(int i=3; i<41; i++) d[i]=d[i-1]+d[i-2]+1;
    for(int i=40; i>=2; i--) if(n-d[i]>=0) n-=(d[i] + 1);
    if(messi[n] == ' ' || n<0)cout<<"Messi Messi Gimossi";
    else cout<<messi[n]<<'\n';
}
