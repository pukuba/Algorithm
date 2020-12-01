#include <bits/stdc++.h>

using namespace std;
int d[5][5][100001];
int ddr[100001];
int cnt12=0;
int check(int a,int b){
    if(a==0) return 2;
    else if(abs(a-b)==2) return 4;
    else if(a==b) return 1;
    else return 3;
}
int DDR(int i,int j,int cnt){
    if(cnt==cnt12) return 0;
    if(d[i][j][cnt]!=-1) return d[i][j][cnt];
    int lf=DDR(ddr[cnt],j,cnt+1)+check(i,ddr[cnt]);
    int rf=DDR(i,ddr[cnt],cnt+1)+check(j,ddr[cnt]);
    return d[i][j][cnt]=min(lf,rf);
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(d,-1,sizeof(d));
    while(1){
        int x;
        cin>>x;
        if(x!=0){
            ddr[cnt12]=x;
            cnt12++;
        }
        else{
            break;
        }
    }
    cout<<DDR(0,0,0);
}
