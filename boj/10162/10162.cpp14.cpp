#include <iostream>

using namespace std;
int main(){
    const int a=300,b=60,c=10;
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,ans1=0,ans2=0,ans3=0;
    cin>>n;
    if(n%10!=0){
        cout<<"-1\n";
        return 0;
    }
    else{
        ans1=n/a;
        n%=a;
        ans2=n/b;
        n%=b;
        ans3=n/c;
        n%=c;
    }
    printf("%d %d %d\n",ans1,ans2,ans3);

}