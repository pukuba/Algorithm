#include <bits/stdc++.h>

using namespace std;
long long d[111],dx[3]={1,3,4},n;
bool check[111][111];
queue<pair<int,int> > q;
/*
 1 SK
 2 CY
 3 SK
 4 SK
 5 SK
 6 SK
 7 CY
 8 SK
 9 CY
 10 SK // 7 6 8
 11 
 */
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    if(n%7 == 2 || n%7 == 0){
        cout<<"CY";
    }else{
        cout<<"SK";
    }
}