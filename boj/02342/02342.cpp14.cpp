#include <bits/stdc++.h>

using namespace std;
int d[5][5][100001];
int ddr[100001];
int cnt12=0;
int DDR(int i,int j,int cnt){
    if(cnt==cnt12) return 0;
    int res=d[i][j][cnt];
    if(res!=-1) return d[i][j][cnt];
    if(i==0 && j==0){
        return d[i][j][cnt] = DDR(ddr[cnt],j,cnt+1)+2;
    }
    if(i==ddr[cnt]){
        return d[i][j][cnt] = DDR(i,j,cnt+1)+1;
    }
    else if(j==ddr[cnt]){
        return d[i][j][cnt] = DDR(i,j,cnt+1)+1;
    }
    int lf=0;
    if(i==0){
        lf = DDR(ddr[cnt],j,cnt+1)+2;
    }
    else if(abs(i-ddr[cnt])==2){
        lf = DDR(ddr[cnt],j,cnt+1)+4;
    }
    else{
        lf = DDR(ddr[cnt],j,cnt+1)+3;
    }
    int rf=0;
    if(j==0){
        rf = DDR(i,ddr[cnt],cnt+1)+2;
    }
    else if(abs(j-ddr[cnt])==2){
        rf = DDR(i,ddr[cnt],cnt+1)+4;
    }
    else{
        rf = DDR(i,ddr[cnt],cnt+1)+3;
    }
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
