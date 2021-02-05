#include <iostream>

using namespace std;
int main(){
    int a[32]={0,},b;
    for(int i=1; i<=28; i++){
        cin>>b;
        a[b]=1;
    }
    for(int i=1; i<=30; i++){
        if(a[i]!=1){
            cout<<i<<'\n';
        }
    }
}  