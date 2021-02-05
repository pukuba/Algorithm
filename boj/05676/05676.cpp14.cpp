#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll tree[444444];
int a[111111],n,m;
ll init(int node,int start,int end){
   if(start == end) return tree[node] = a[start];
   return tree[node] = init(node*2,start,start+end>>1) * init(node*2+1,(start+end>>1)+1,end);
}
void update(int node,int start,int end,int pos,int diff){
   if(pos < start || end < pos) return;
   if(pos <= start && end <= pos){
      tree[node] = diff;
      return;
   }
   update(node*2,start,start+end>>1,pos,diff);
   update(node*2+1,(start+end>>1)+1,end,pos,diff);
   tree[node] = tree[node*2] * tree[node*2+1];
}
ll query(int node,int start,int end,int left,int right){
   if(start > right || end < left) return 1;
   if(left <= start && end <= right) return tree[node];
   return query(node*2,start,start+end>>1,left,right) * query(node*2+1,(start+end>>1)+1,end,left,right);
}
int main(){
   ios_base::sync_with_stdio(0);cin.tie(nullptr);
   while((cin>>n>>m)){
      memset(tree,false,sizeof(tree));
      memset(a,false,sizeof(a));
      for(int i=1; i<=n; i++){
         int x;
         cin>>x;
         if(x == 0) a[i]=0;
         if(x > 0) a[i]=1;
         if(x < 0) a[i]=-1;
      }
      init(1,1,n);
      while(m--){
         char type;
         int from,to;
         cin>>type>>from>>to;
         if(type == 'C'){
            if(to > 0) update(1,1,n,from,1);
            if(to < 0) update(1,1,n,from,-1);
            if(to == 0) update(1,1,n,from,0);
         }
         if(type == 'P'){
            int check = query(1,1,n,from,to);
            if(check == 0) cout<<"0";
            if(check > 0) cout<<"+";
            if(check < 0) cout<<"-";
         }
      }
      cout<<'\n';
   }
}
