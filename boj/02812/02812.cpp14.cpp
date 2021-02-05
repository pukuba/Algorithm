#include <bits/stdc++.h>

using namespace std;
int n,k,x;
stack<int> stk,save;
int main(){
    scanf("%d %d",&n,&k);
    scanf("%1d",&x);
    stk.push(x);
    for(int i=0; i<n-1; i++){
        int x;
        scanf("%1d",&x);
        if(x==9){
            while(k && !stk.empty() && stk.top()<9 ){
                k--;
                stk.pop();
            }
            stk.push(x);
        }
        else if(stk.top()<x && k){
            bool ang=false;
            while(!stk.empty() && stk.top()<x && k &&stk.top()!=9){
                ang=true;
                k--;
                stk.pop();
            }
            if(ang==false){
                stk.pop();
                k--;
            }
            stk.push(x);
        }
        else stk.push(x);
    }
    while(k-- && !stk.empty()) stk.pop();
    while(!stk.empty()){
        save.push(stk.top());
        stk.pop();
    }
    while(!save.empty()){
        cout<<save.top();
        save.pop();
    }
}
