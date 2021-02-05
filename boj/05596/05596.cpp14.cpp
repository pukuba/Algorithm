#include <iostream>
#include <algorithm>

using namespace std;
int main(){
    int a,ans1=0,ans2=0;
    for(int i=1; i<=8; i++){
        cin>>a;
        if(i<=4){
            ans1+=a;
        }
        if(i>=5){
            ans2+=a;
        }
    }
    cout<<max(ans1,ans2)<<'\n';
}