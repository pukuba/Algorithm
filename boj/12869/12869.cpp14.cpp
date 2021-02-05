#include <bits/stdc++.h>

using namespace std;
int d[61][61][61];
int d1[61];
int d2[61][61];
int main(){
   int n;
   cin>>n;
   if(n==1){
      fill(&d1[0],&d1[61],987654321);
      int a;
      cin>>a;
      d1[a]=0;
      for(int i=a; i>=0; i--){
         if(i-9<=0) d1[0]=min(d1[0],d1[i]+1);
         else d1[i-9]=min(d1[i-9],d1[i]+1);
      }
      cout<<d1[0]<<'\n';
      return 0;
   }
   else if(n==2){
      for(int i=0; i<61; i++){
         for(int j=0; j<61; j++){
            d2[i][j]=987654321;
         }
      }
      int a,b;
      cin>>a>>b;
      d2[a][b]=0;
      for(int i=a; i>=0; i--){
         for(int j=b; j>=0; j--){
            if(i-9<=0 && j-3<=0) d2[0][0]=min(d2[i][j]+1,d2[0][0]);
            if(i-9<=0 && j-3>=0) d2[0][j-3]=min(d2[i][j]+1,d2[0][j-3]);
            if(i-9>=0 && j-3<=0) d2[i-9][0]=min(d2[i][j]+1,d2[i-9][0]);
            if(i-9>=0 && j-3>=0) d2[i-9][j-3]=min(d2[i-9][j-3],d2[i][j]+1);
            if(i-3<=0 && j-9<=0) d2[0][0]=min(d2[i][j]+1,d2[0][0]);
            if(i-3<=0 && j-9>=0) d2[0][j-9]=min(d2[i][j]+1,d2[0][j-9]);
            if(i-3>=0 && j-9<=0) d2[i-3][0]=min(d2[i][j]+1,d2[i-3][0]);
            if(i-3>=0 && j-9>=0) d2[i-3][j-9]=min(d2[i-3][j-9],d2[i][j]+1);
         }
      }
      cout<<d2[0][0]<<'\n';
      return 0;
   }
   else{
      for(int i=0; i<61; i++){
         for(int j=0; j<61; j++){
            for(int k=0; k<61; k++){
               d[i][j][k]=987654321;
            }
         }
      }
      int a,b,c;
      cin>>a>>b>>c;
      d[a][b][c]=0;
      for(int i=a; i>=0; i--){
         for(int j=b; j>=0; j--){
            for(int k=c; k>=0; k--){
               int a_a=(i-9>=0)?i-9:0;
               int a_b=(i-3>=0)?i-3:0;
               int a_c=(i-1>=0)?i-1:0;
               int b_a=(j-9>=0)?j-9:0;
               int b_b=(j-3>=0)?j-3:0;
               int b_c=(j-1>=0)?j-1:0;
               int c_a=(k-9>=0)?k-9:0;
               int c_b=(k-3>=0)?k-3:0;
               int c_c=(k-1>=0)?k-1:0;
               d[a_a][b_b][c_c]=min(d[i][j][k]+1,d[a_a][b_b][c_c]);
               d[a_a][b_c][c_b]=min(d[i][j][k]+1,d[a_a][b_c][c_b]);
               d[a_b][b_a][c_c]=min(d[i][j][k]+1,d[a_b][b_a][c_c]);
               d[a_b][b_c][c_a]=min(d[i][j][k]+1,d[a_b][b_c][c_a]);
               d[a_c][b_a][c_b]=min(d[i][j][k]+1,d[a_c][b_a][c_b]);
               d[a_c][b_b][c_a]=min(d[i][j][k]+1,d[a_c][b_b][c_a]);
            }
         }
      }
      cout<<d[0][0][0]<<'\n';
      return 0;
   }
}