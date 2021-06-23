#include <cstdio>

int t,ans;
int main(){
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        ans ^= n;
    } printf("%s",ans ? "koosaga":"cubelover");
}