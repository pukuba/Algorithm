#include <iostream>
#include <algorithm>

using namespace std;
int main(){
    int a[9],ans=0,bt=1;
    for(int i=0; i<9; i++){
        cin>>a[i];
        ans+=a[i];
    }
    ans-=100;
    for(int i=0; i<8; i++){
        for(int j=i+1; j<9; j++){
            if(a[i]+a[j]==ans){
                bt--;
                a[i]=-1;
                a[j]=-1;
                break;
            }
            if(bt=0){
                break;
            }
        }
    }
    sort(a,a+9);
    for(int i=0; i<9; i++){
        if(a[i]<0){
            continue;
        }
        cout<<a[i]<<'\n';
    }

}