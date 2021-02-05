#include <bits/stdc++.h>

using namespace std;
int arr[225],n;
int main(){
    for(int i=1; i<=224; i++) arr[i]=i*i;
    cin>>n;
    for(int i=1; i<=224; i++){
        if(n==arr[i]){
            cout<<1<<'\n';
            return 0;
        }
    }
    for(int i=1; i<=224; i++){
        for(int j=1; j<=224; j++){
            if(n==arr[i]+arr[j]){
                cout<<2<<'\n';
                return 0;
            }
        }
    }
    for(int i=1; i<=224; i++){
        for(int j=1; j<=224; j++){
            for(int k=1; k<=224; k++){
                if(n==arr[i]+arr[j]+arr[k]){
                    cout<<3<<'\n';
                    return 0;
                }
            }
        }
    }
    cout<<4<<'\n';
}
