#include <iostream>

using namespace std;
int main(){
    int e,s,m;
    cin>>e>>s>>m;
    int a=1,b=1,c=1,ans=0;
    while(1){
       ans++;
       if(a==e&&s==b&&m==c){
          cout<<ans<<'\n';
          return 0;
      }
      a++,b++,c++;
      if(a>15) a=1;
      if(b>28) b=1;
      if(c>19) c=1;
   }
}
