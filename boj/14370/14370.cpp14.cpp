#include <bits/stdc++.h>

using namespace std;
int n;
int alpha[111];
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++){
        memset(alpha,false,sizeof(alpha));
        string s,ans="";
        cin>>s;
        for(int i=0; i<s.size(); i++) alpha[s[i]]++;
        while(1){
            if(alpha['Z']>0){
                alpha['Z']--;alpha['E']--;alpha['R']--;alpha['O']--;
                ans+='0';
                continue;
            }
            break;
        }
        while(1){
            if(alpha['X']>0){
                alpha['X']--;alpha['I']--;alpha['S']--;
                ans+='6';
                continue;
            }
            break;
        }
        while(1){
            if(alpha['S']>0){
                alpha['S']--;alpha['E']-=2;alpha['V']--;alpha['N']--;
                ans+='7';
                continue;
            }
            break;
        }
        while(1){
            if(alpha['U']>0){
                alpha['R']--;alpha['F']--;alpha['O']--;alpha['U']--;
                ans+='4';
                continue;
            }
            break;
        }
        while(1){
            if(alpha['F']>0){
                alpha['F']--;alpha['I']--;alpha['V']--;alpha['E']--;
                ans+='5';
                continue;
            }
            break;
        }
        while(1){
            if(alpha['W']>0){
                alpha['W']--;alpha['T']--;alpha['O']--;
                ans+='2';
                continue;
            }
            break;
        }
        while(1){
            if(alpha['G']>0){
                alpha['G']--;alpha['E']--;alpha['I']--;alpha['H']--;alpha['T']--;
                ans+='8';
                continue;
            }
            break;
        }
        while(1){
            if(alpha['H']>0){
                alpha['H']--;alpha['T']--;alpha['R']--;alpha['E']-=2;
                ans+='3';
                continue;
            }
            break;
        }
        while(1){
            if(alpha['I']>0){
                alpha['I']--;alpha['N']-=2;alpha['E']--;
                ans+='9';
                continue;
            }
            break;
        }
        while(1){
            if(alpha['O']>0){
                alpha['O']--;alpha['N']--;alpha['E']--;
                ans+='1';
                continue;
            }
            break;
        }
        sort(ans.begin(),ans.end());
        cout<<"Case #"<<i<<": "<<ans<<'\n';
    }
}
