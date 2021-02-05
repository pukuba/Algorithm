#include <bits/stdc++.h>

using namespace std;
deque<int> v[5];
int t,x,y,ans;
pair<int,int> s[5];
bool check[5];
void test(int x){
    if(check[x] == true) return;
    check[x] = 1;
    if(x == 1){
        if(s[x].second != s[x+1].first) test(x+1);
        return;
    }
    else if(x == 4){
        if(s[x].first != s[x-1].second) test(x-1);
        return;
    }
    else{
        if(s[x].first != s[x-1].second) test(x-1);
        if(s[x].second != s[x+1].first) test(x+1);
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    for(int i=1; i<=4; i++){
        for(int j=1; j<=8; j++){
            char x;
            cin>>x;
            v[i].push_back(x-'0');
        }
    }
    cin>>t;
    while(t--){
        cin>>x>>y;
        for(int i=1; i<=4; i++) s[i] = {v[i][6],v[i][2]};
        memset(check, 0, sizeof check);
        test(x);
        for(int i=1; i<=4; i++){
            int cnt = abs(x-i)%2;
            if(check[i]){
                if(cnt == 0){
                    if(y == -1){
                        int tmp = v[i].front();
                        v[i].pop_front();
                        v[i].push_back(tmp);
                    }
                    else{
                        int tmp = v[i].back();
                        v[i].pop_back();
                        v[i].push_front(tmp);
                    }
                }
                else{
                    if(y == -1){
                        int tmp = v[i].back();
                        v[i].pop_back();
                        v[i].push_front(tmp);
                    }
                    else{
                        int tmp = v[i].front();
                        v[i].pop_front();
                        v[i].push_back(tmp);
                    }
                }
            }
        }
        if(!t){
            ans += v[1][0] == 1 ? 1 : 0;
            ans += v[2][0] == 1 ? 2 : 0;
            ans += v[3][0] == 1 ? 4 : 0;
            ans += v[4][0] == 1 ? 8 : 0;
            cout<<ans<<'\n';
            return 0;
        }
    }
    
}