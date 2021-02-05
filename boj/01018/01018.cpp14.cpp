#include <bits/stdc++.h>

using namespace std;
string _set1[8]={{"WBWBWBWB"},{"BWBWBWBW"},{"WBWBWBWB"},{"BWBWBWBW"},{"WBWBWBWB"},{"BWBWBWBW"},{"WBWBWBWB"},{"BWBWBWBW"}},_set2[8]={{"BWBWBWBW"},{"WBWBWBWB"},{"BWBWBWBW"},{"WBWBWBWB"},{"BWBWBWBW"},{"WBWBWBWB"},{"BWBWBWBW"},{"WBWBWBWB"}};
int n,m,ra=987654321;
char _map[101][101];
pair<int,int> ans;
pair<int,int> check(int y,int x){
    int ans1=0,ans2=0;
    for(int i=y; i<=y+7; i++){
        for(int j=x; j<=x+7; j++){
            if(_set1[i-y][j-x]!=_map[i][j]) ans1++;
            if(_set2[i-y][j-x]!=_map[i][j]) ans2++;
        }
    }
    return {ans1,ans2};
}
int main(){
    ans.first=987654321,ans.second=987654321;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>_map[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ans=check(i,j);
            ra=min({ans.first,ans.second,ra});
        }
    }
    cout<<ra<<'\n';
}
