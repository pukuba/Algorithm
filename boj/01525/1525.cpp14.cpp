#include <bits/stdc++.h>

using namespace std;
set<string> check;
string ans="123456780",s;
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
bool in(int a, int b){ return 0<=a && a<=2 && 0<=b && b<=2; }
string change(string str, int fir_idx, int sec_idx){
    char change_1 = str[fir_idx];
    str[fir_idx]=str[sec_idx];
    str[sec_idx]=change_1;
    return str;
}
struct point{
    string s;
    int cnt;
};
queue<point> q;
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    for(int i=0; i<9; i++){
        int x;
        cin>>x;
        string c=to_string(x);
        s+=c;
    }
    q.push({s,0});
    check.insert(s);
    while(!q.empty()){
        auto [_string,cnt] = q.front();
        q.pop();
        if(_string == ans){
            cout<<cnt<<'\n';
            return 0;
        }
        int _map[3][3];
        for(int i=0; i<3; i++) _map[0][i]=_string[i]-'0';
        for(int i=3; i<6; i++) _map[1][i-3]=_string[i]-'0';
        for(int i=6; i<9; i++) _map[2][i-6]=_string[i]-'0';
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(_map[i][j]==0) for(int k=0; k<4; k++){
                    int next_x = j+dx[k];
                    int next_y = i+dy[k];
                    if(!in(next_y,next_x)) continue;
                    string ps ="";
                    ps+=(char(_map[0][0]+'0')),ps+=(char(_map[0][1]+'0')),ps+=(char(_map[0][2]+'0'));
                    ps+=(char(_map[1][0]+'0')),ps+=(char(_map[1][1]+'0')),ps+=(char(_map[1][2]+'0'));
                    ps+=(char(_map[2][0]+'0')),ps+=(char(_map[2][1]+'0')),ps+=(char(_map[2][2]+'0'));
                    int fir_idx,sec_idx;
                    char _fir=char(_map[i][j]+'0'),_sec=char(_map[next_y][next_x]+'0');
                    for(int l=0; l<ps.size(); l++){
                        if(ps[l]==_fir) fir_idx = l;
                        if(ps[l]==_sec) sec_idx = l;
                    }
                    string _push =change(ps,fir_idx,sec_idx);
                    if(!check.count(_push)){
                        check.insert(_push);
                        q.push({_push,cnt+1});
                    }
                }
            }
        }
    }
    cout<<-1<<'\n';
}
