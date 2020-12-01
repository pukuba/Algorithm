#include <bits/stdc++.h>

using namespace std;
int arr[10004];
int n,m,k,d,b,c;
int main(){
    while(1){
        memset(arr,0,sizeof(arr));
        scanf("%d %d.%d", &n, &m, &k);
        int _size = m * 100 + k;
        if(n==0 && _size==0) break;
        vector<pair<int,int > > a;
        for(int i=0; i<n; i++){
            scanf("%d %d.%d",&d, &b, &c);
            int pay = b * 100 + c;
            for(int j = pay; j <= _size; j++){
                arr[j] = max(arr[j], arr[j - pay] + d);
            }
        }
        cout << arr[_size] << "\n";
    }
}
