#include <bits/stdc++.h>

using namespace std;
string s;
int main(){
    cin>>s;
    if(s.size()<=2) cout<<"◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
    else{
        for(int i=0; i<s.size()-2; i++){
            if(s[i+2]-s[i+1]!=s[i+1]-s[i]){
                cout<<"흥칫뿡!! <(￣ ﹌ ￣)>";
                return 0;
            }
        }
        cout<<"◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
    }
}
