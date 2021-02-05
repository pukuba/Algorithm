#include <bits/stdc++.h>

using namespace std;
int arr[22][22];
bool in(int y,int x,int c){return 1<=y && y<=19 && 1<=x && x<=19 && arr[y][x] == c;}
int u(int y, int x,int c){
    if(in(y,x,c) == 0) return 0;
    return u(y-1,x,c) + 1;
}
int d(int y,int x,int c){
    if(in(y,x,c) == 0) return 0;
    return d(y+1,x,c) + 1;
}
int r(int y,int x,int c){
    if(in(y,x,c) == 0) return 0;
    return r(y,x+1,c) + 1;
}
int l(int y,int x,int c){
    if(in(y,x,c) == 0) return 0;
    return l(y,x-1,c) + 1;
}
int rd(int y,int x,int c){
    if(in(y,x,c) == 0) return 0;
    return rd(y+1,x+1,c) + 1;
}
int lu(int y,int x,int c){
    if(in(y,x,c) == 0) return 0;
    return lu(y-1,x-1,c) + 1;
}
int ru(int y,int x,int c){
    if(in(y,x,c) == 0) return 0;
    return ru(y-1,x+1,c) + 1;
}
int ld(int y,int x,int c){
    if(in(y,x,c) == 0) return 0;
    return ld(y+1,x-1,c) + 1;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    for(int i=1; i<=19; i++){
        for(int j=1; j<=19; j++){
            cin>>arr[i][j];
        }
    }
    for(int x=1; x<=19; x++){
        for(int y=1; y<=19; y++){
            if(arr[y][x]){
                if(d(y,x,arr[y][x]) + u(y,x,arr[y][x]) - 1 == 5 || r(y,x,arr[y][x]) + l(y,x,arr[y][x]) - 1 == 5 || rd(y,x,arr[y][x]) + lu(y,x,arr[y][x]) - 1 == 5 || ru(y,x,arr[y][x]) + ld(y,x,arr[y][x]) - 1 == 5){
                    cout<<arr[y][x]<<'\n'<<y<<' '<<x<<'\n';
                    return 0;
                }
            }

        }
    }
    cout<<0<<'\n';
}
