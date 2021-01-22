#include <iostream>
#include <algorithm>

using namespace std;
int main(){
    int n,m,val=0,ans=0;
    cin>>n>>m;
    val+=m;
    for(int i=0; i<n; i++){
        int in,out;
        cin>>in>>out;
        val+=in,val-=out;
        ans=max(ans,val);
        if(val<0){
            cout<<0;
            return 0;
        }
    }
    cout<<ans<<'\n';
}
