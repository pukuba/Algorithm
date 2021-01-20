#include <iostream>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int m,n,x,y;
        cin>>m>>n>>x>>y;
        x-=1;
        y-=1;
        bool check=false;
        for(int i=x; i<(n*m); i+=m){
            if(i%n==y){
                cout<<i+1<<'\n';
                check=true;
                break;
            }
        }
        if(check==false){
            cout<<"-1"<<'\n';
        }
    }
}
