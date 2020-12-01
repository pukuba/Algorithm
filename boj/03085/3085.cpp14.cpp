#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int temp=0;
int check(vector<string> &a){
    int s=a.size();
    int ans=1;
    for(int i=0; i<s; i++){
        int cnt=1;
        for(int j=1; j<s; j++){
            if(a[i][j]==a[i][j-1]){
                cnt++;
            }
            else{
                cnt=1;
            }
            if(ans<cnt) ans=cnt;
        }
        cnt=1;
        for(int j=1; j<s; j++){
            if(a[j][i]==a[j-1][i]){
                cnt++;
            }
            else{
                cnt=1;
            }
            if(ans<cnt) ans=cnt;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<string> s(n);
    for(int i=0; i<n; i++){
        cin>>s[i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            swap(s[i][j],s[i][j+1]);
            temp=max(temp,check(s));
            swap(s[i][j],s[i][j+1]);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            swap(s[j][i],s[j+1][i]);
            temp=max(temp,check(s));
            swap(s[j][i],s[j+1][i]);
        }
    }
    cout<<temp<<'\n';
}
