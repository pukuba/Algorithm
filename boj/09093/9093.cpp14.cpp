#include <bits/stdc++.h>

using namespace std;
int n;
int main(){
    cin>>n;
    cin.ignore();
    while(n--){
        string s,save;
        getline(cin,s);
        int point=-1;
        for(int i=0; i<s.size(); i++){
            if(s[i]==' '){
                reverse(save.begin(),save.end());
                cout<<save<<' ';
                save.clear();
            }
            else save+=s[i];
        }
        reverse(save.begin(),save.end());
        cout<<save<<'\n';
    }
}
