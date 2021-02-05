#include <iostream>

int main(){
    int n,cnt=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        int x;
        scanf("%1d",&x);
        if(x==1) cnt++;
    }
    printf("%d",cnt);
}