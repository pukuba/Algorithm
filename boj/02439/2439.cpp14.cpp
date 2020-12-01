#include <iostream>

using namespace std;
int n;
void star_Draw(int star){
    if(n>star){
        cout<<"*";
        star_Draw(star+1);
    }
    else{
        return;
    }
}
void blank_Draw(int blank,int check){
    if(blank<n){
        cout<<" ";
        blank_Draw(blank+1,check+1);
    }
    else{
        star_Draw(check);
    }
}
void star(int num){
    if(num==n+1) return;
    blank_Draw(num,0);
    cout<<"\n";
    star(num+1);
}
int main(){
    cin>>n;
    star(1);
}
