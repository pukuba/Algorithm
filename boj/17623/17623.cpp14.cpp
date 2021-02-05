#include <bits/stdc++.h>

using namespace std;
string d[1001]={"","()","{}","[]"};
int t,n;
bool check(string s1,string s2){
    string point1,point2;
    if(s1.size()==0 && s2.size()==0) return false;
    if(s1.size()==0) return true;
    
    
    for(int i=0; i<s1.size(); i++){
        if(s1[i]==')') point1+='2';
        if(s1[i]=='(') point1+='1';
        if(s1[i]=='{') point1+='3';
        if(s1[i]=='}') point1+='4';
        if(s1[i]=='[') point1+='5';
        if(s1[i]==']') point1+='6';
    }
    for(int i=0; i<s2.size(); i++){
        if(s2[i]==')') point2+='2';
        if(s2[i]=='(') point2+='1';
        if(s2[i]=='{') point2+='3';
        if(s2[i]=='}') point2+='4';
        if(s2[i]=='[') point2+='5';
        if(s2[i]==']') point2+='6';
    }
    if(s1.size()!=s2.size()){
        if(s1.size()>s2.size()) return true;
        else return false;
    }
    if(point1 > point2) return true;
    else return false;
}
int main(){
    for(int i=1; i<1001; i++){
        if(i%2==0 && check(d[i],'('+d[i/2]+')')) d[i]='('+ d[i/2]+')';
        if(i%3==0 && check(d[i],'{'+d[i/3]+'}')) d[i]='{'+ d[i/3]+'}';
        if(i%5==0 && check(d[i],'['+d[i/5]+']')) d[i]='['+ d[i/5]+']';
        for(int j=1; j<=i; j++){
            if(check(d[i],d[i-j]+d[j])) d[i]=d[i-j]+d[j];
        }
        /*if(check(d[i],"()"+d[i-1]))
        if(check(d[i],"{}"+d[i-2]))
        if(check(d[i],"[]"+d[i-3]))*/
        
    }
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<d[n]<<'\n';
    }
}
