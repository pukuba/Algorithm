#include <bits/stdc++.h>

using namespace std;
struct pos{
    int sz,h,w;
    bool operator < (const pos &a) const {
        if(sz == a.sz){
            return h<a.h;
        }
        return sz < a.sz;
    }
};
vector<pos> v;
int a,b;
int binary(int x){
    int s = 0, e = v.size()-1,ret = -1;
    while(s<=e){
        int mid = s + e >> 1;
        if(v[mid].sz > x){
            s = mid + 1;
        }
        else if(v[mid].sz < x){
            e = mid - 1;
        }
        else{
            e = mid - 1;
            ret = mid;
        }
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    for(int i=1; i<=150; i++){
        for(int j=i+1; j<=150; j++){
            v.push_back({(i*i)+(j*j),i,j});
        }
    }
    sort(v.begin(),v.end());
    while(1){
        cin>>a>>b;
        if(a == 0 && b == 0){
            return 0;
        }
        int idx = binary((a*a)+(b*b));
        for(;;){
            if(v[idx].h == a && v[idx].w == b){
                break;
            }
            idx++;
        }
        cout<<v[idx+1].h<<' '<<v[idx+1].w<<'\n';
    }
    
}
