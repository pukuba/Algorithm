#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
struct info{int type,stats1,stats2;}room[133333];
int n,m;
ll high = 1e12,low=1;
bool go(ll hp){
    ll attack_p = m,health = hp;
    for(int i=1; i<=n; i++){
        if(room[i].type == 1){
            ll turn = (room[i].stats2 / attack_p) + (room[i].stats2 % attack_p ? 1 : 0);
            turn--;
            health -= room[i].stats1 * turn;
            if(health <= 0) return false;
        }
        if(room[i].type == 2) attack_p += room[i].stats1, health = min(hp,health+room[i].stats2);
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m;
    high *= n;
    for(int i=1; i<=n; i++) cin>>room[i].type>>room[i].stats1>>room[i].stats2;
    while(low <= high){
        ll mid = low+high>>1;
        if(go(mid)) high = mid-1;
        else low = mid+1;
    }
    cout<<low<<'\n';
}