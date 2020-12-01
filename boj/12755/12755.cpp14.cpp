#include <bits/stdc++.h>

using namespace std;
int n,cnt;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<=100000000; i++){
        int k = log10(i*10);
        cnt += k;
        if(cnt >= n){
            cnt -= k;
            string s = to_string(i);
            for(int j=0; j<s.size(); j++){
                cnt++;
                if(cnt == n){
                    cout<<s[j];
                    return 0;
                }
            }
        }
    }
}