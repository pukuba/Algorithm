#include <bits/stdc++.h>
#define rd (rand()%n)+1
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
struct point{ld x,y;};
point p[100111];
bool check[100111];
ll gcd(ll a,ll b){return a%b ? gcd(b,a%b) : b;}
pair<ll,ll> make(int fir,int sec){
    point a=p[fir],b=p[sec];
    if(a.x > b.x) swap(a,b);
    ll z1 = (a.y - b.y), z2 = (a.x - b.x); //기울기
    if(z1 == 0) return {1e10,0};
    else if(z2 == 0) return {0,1e10};
    return {z2/gcd(z2,z1),z1/gcd(z2,z1)};
}
bool go(int fir,int sec){
    memset(check,false,sizeof(check));
    pair<ll,ll> comp = make(fir,sec);
    check[fir] = check[sec] = true;
    vector<ll> es;
    for(int i=1; i<=n; i++){
        if(check[i]) continue;
        if(comp == make(fir,i)) check[i] = true;
        else es.push_back(i);
    }
    if(es.size() < 3) return true;
    comp = make(es[0],es[1]);
    check[es[0]] = check[es[1]] = true;
    for(int i=1; i<=n; i++){
        if(check[i]) continue;
        if(comp == make(es[0],i)) check[i] = true;
    }
    for(int i=1; i<=n; i++) if(!check[i]) return false;
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>p[i].x>>p[i].y;
    if(n < 5){
        cout<<"success";
        return 0;
    }
    for(int i=1; i<=10; i++){
        int first_idx=rd,second_idx=rd;
        while(first_idx == second_idx) first_idx=rd,second_idx=rd;
        if(go(first_idx,second_idx)){
            cout<<"success";
            return 0;
        }
    }
    cout<<"failure";
}
