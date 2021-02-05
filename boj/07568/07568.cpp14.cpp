#include <iostream>

using namespace std;
struct temp{
    int x,y,rank;
};
int main(){
    int n;
    cin>>n;
    temp data[n];
    for(int i=0; i<n; i++){
        int k1,k2;
        cin>>k1>>k2;
        data[i].x=k1;
        data[i].y=k2;
        data[i].rank=1;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(data[i].x<data[j].x && data[i].y<data[j].y){
                data[i].rank++;
            }
        }
    }
    for(int i=0; i<n; i++){
        cout<<data[i].rank<<' ';
    }
}
