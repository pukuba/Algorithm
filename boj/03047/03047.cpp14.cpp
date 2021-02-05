#include <iostream>
#include <algorithm>

using namespace std;
int mxs,mns;
int main(){
    int a,b,c;cin>>a>>b>>c;
    mxs=max({a,b,c});
    mns=min({a,b,c});
    if(a!=mxs&&a!=mns){
        b=a;
    }
    else if(c!=mxs&&c!=mns){
        b=c;
    }
    a=mns;
    c=mxs;
    string s;
    cin>>s;
    if(s=="ABC"){
        printf("%d %d %d",a,b,c);
    }
    else if(s=="ACB"){
        printf("%d %d %d",a,c,b);
    }
    else if(s=="BAC"){
        printf("%d %d %d",b,a,c);
    }
    else if(s=="BCA"){
        printf("%d %d %d",b,c,a);
    }
    else if(s=="CAB"){
        printf("%d %d %d",c,a,b);
    }
    else if(s=="CBA"){
        printf("%d %d %d",c,b,a);
    }
}