#include <bits/stdc++.h>

using namespace std;
int n,p[292929];
double o,q,w,e;
void f(int x){
    if(p[x] == 0) p[x] = 1;
    else if(p[x] == 1) p[x] = 2;
    else if(p[x] == 2) p[x] = 0;
}

int main(){
    scanf("%lf %d",&o,&n);
    for(int i=1,x; i<=n; i++){
        char c;
        scanf("%d %c",&x,&c);
        if(c == 'L') for(int i=x-1; i>=1; i--) f(i);
        if(c == 'R') for(int i=x+1; i<=100; i++) f(i);
    }
    for(int i=1; i<=100; i++){
        if(!p[i]) q++;
        if(p[i] == 1) w++;
        if(p[i] == 2) e++;
    }
    double r = o*(q/100),g = o*(w/100),b = o*(e/100);
    printf("%.2lf\n%.2lf\n%.2lf",r,g,b);
}