#include <bits/stdc++.h>

using namespace std;
int n;
int f(int k){
    if(k==1 || !k) return 1;
    return f(k-1)*k;
}
int main(){
    scanf("%d",&n);
    printf("%d",f(n));
}
