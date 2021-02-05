#include <iostream>

using namespace std;
int ans[1001][1001]={0,};
int main(){
    int t,print=0;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        for(int i=a; i<a+10; i++){
            for(int j=b; j<b+10; j++){
                ans[i][j]++;
            }
        }
    }
    for(int i=0; i<=1000; i++){
        for(int j=0; j<=1000; j++){
            if(ans[i][j]!=0){
               print++; 
            }
        }
    }
    cout<<print<<'\n';
}