#include <iostream>

using namespace std;
void prt(int c,int d,int dis){
    if(dis<c){
        cout<<"*";
        prt(c,d,dis+1);
    }
    else{
        return;
    }
}
void star(int a,int b){
    if(b==a) return;
    else{
        prt(a+1,b,0);
        cout<<"\n";
        star(a+1,b);
    }
}
int main(){
    int n;
    cin>>n;
    star(0,n);
}
