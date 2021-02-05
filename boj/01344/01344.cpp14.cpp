#include <bits/stdc++.h>

using namespace std;
double d[20][20][20];
bool prime[101];
double ap,bp;
double dfs(int a,int b,int cnt){
    if(cnt>17){
        return (!prime[a] || !prime[b]) ? 1.0 : 0.0;
    }
    if(d[cnt][a][b] > -0.5) return d[cnt][a][b];
    double & ret = d[cnt][a][b];
    ret = 0;
    ret +=dfs(a,b+1,cnt+1)*(1-ap)*(bp);
    ret +=dfs(a,b,cnt+1)*(1-ap)*(1-bp);
    ret +=dfs(a+1,b+1,cnt+1)*ap*bp;
    ret +=dfs(a+1,b,cnt+1)*ap*(1-bp);
    return ret;
}
int main(){
    memset(d,-1,sizeof(d));
    scanf("%lf %lf",&ap,&bp);
    ap/=100,bp/=100;
    prime[0]=prime[1]=1;
    for(int i=2; i<=100; i++){
        if(!prime[i]){
            for(int j=i+i; j<=100; j+=i){
                prime[j]=true;
            }
        }
    }
    printf("%.6lf",dfs(0,0,0));
}

