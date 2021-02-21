#include <bits/stdc++.h>

using namespace std;
vector<int> v;
int n,ans;
string s[11];
set<char> st;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=0; i<=9; i++)  v.push_back(i);
    for(int i=1; i<=n; i++){
        cin>>s[i];
        for(char c:s[i]) st.insert(c);
    }
    char tmp = 'A';
    for(char a:st){
        for(int i=1; i<=n; i++){
            for(char&c:s[i]){
                if(c == a) c = tmp;
            }
        }
        tmp++;
    }
    do{
        int temp = 0;
        for(int i=1; i<=n; i++){
            for(int j=s[i].size()-1,k = 1; j>=0; j--,k*=10){
                temp += v[s[i][j]-'A'] * k;
            }
        }
        ans = max(ans,temp);
    }while(next_permutation(v.begin(), v.end()));
    cout<<ans<<'\n';
}
