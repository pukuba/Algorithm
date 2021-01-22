#include <bits/stdc++.h>

using namespace std;
char front[3][3],back[3][3],up[3][3],lt[3][3],rt[3][3],down[3][3];
int t;
void cube_raset(){
    for(int i=0; i<3; i++) for(int j=0; j<3; j++)
        front[i][j]='r',lt[i][j]='g',rt[i][j]='b',down[i][j]='y',up[i][j]='w',back[i][j]='o';
}
void in_rotate1(char c[3][3]){
    vector<char> temp;
    for(int i=0; i<3; i++) for(int j=0; j<3; j++) temp.push_back(c[i][j]);
    c[0][0]=temp[6],c[0][1]=temp[3],c[0][2]=temp[0],c[1][0]=temp[7],c[1][1]=temp[4];
    c[1][2]=temp[1],c[2][0]=temp[8],c[2][1]=temp[5],c[2][2]=temp[2];
}
void in_rotate2(char c[3][3]){
    vector<char> temp;
    for(int i=0; i<3; i++) for(int j=0; j<3; j++) temp.push_back(c[i][j]);
    c[0][0]=temp[2],c[0][1]=temp[5],c[0][2]=temp[8],c[1][0]=temp[1],c[1][1]=temp[4];
    c[1][2]=temp[7],c[2][0]=temp[0],c[2][1]=temp[3],c[2][2]=temp[6];
}
void up_rotate(){
    char temp;
    for (int i=0; i<3; i++) {
        temp=front[0][i];
        front[0][i]=rt[0][i];
        rt[0][i]=back[0][2-i];
        back[0][2-i]=lt[0][i];
        lt[0][i]=temp;
    }
    in_rotate1(up);
}
void back_rotate(){
    char temp;
    for(int i=0; i<3; i++){
        temp=up[0][i];
        up[0][i]=rt[i][2];
        rt[i][2]=down[2][2-i];
        down[2][2-i]=lt[2-i][0];
        lt[2-i][0]=temp;
    }
    in_rotate2(back);
}
void right_rotate(){
    char temp;
    for(int i=0; i<3; i++) {
        temp=front[i][2];
        front[i][2]=down[i][2];
        down[i][2]=back[2-i][2];
        back[2-i][2]=up[i][2];
        up[i][2]=temp;
    }
    in_rotate1(rt);
}
void front_rotate(){
    char temp;
    for(int i=0; i<3; i++) {
        temp=up[2][i];
        up[2][i]=lt[2-i][2];
        lt[2-i][2]=down[0][2-i];
        down[0][2-i]=rt[i][0];
        rt[i][0]=temp;
    }
    in_rotate1(front);
}
void left_rotate(){
    char temp;
    for(int i=0; i<3; i++) {
        temp=front[i][0];
        front[i][0]=up[i][0];
        up[i][0]=back[2-i][0];
        back[2-i][0]=down[i][0];
        down[i][0]=temp;
    }
    in_rotate1(lt);
}
void down_rotate(){
    char temp;
    for(int i=0; i<3; i++) {
        temp=front[2][i];
        front[2][i]=lt[2][i];
        lt[2][i]=back[2][2-i];
        back[2][2-i]=rt[2][i];
        rt[2][i]=temp;
    }
    in_rotate1(down);
}
void go(string s){
    if(s[0]=='U'){
        if(s[1]=='+') up_rotate();
        if(s[1]=='-') for(int i=0; i<3; i++) up_rotate();
    }
    if(s[0]=='B'){
        if(s[1]=='+') back_rotate();
        if(s[1]=='-') for(int i=0; i<3; i++) back_rotate();
    }
    if(s[0]=='R'){
        if(s[1]=='+') right_rotate();
        if(s[1]=='-') for(int i=0; i<3; i++) right_rotate();
    }
    if(s[0]=='F'){
        if(s[1]=='+') front_rotate();
        if(s[1]=='-') for(int i=0; i<3; i++) front_rotate();
    }
    if(s[0]=='L'){
        if(s[1]=='+') left_rotate();
        if(s[1]=='-') for(int i=0; i<3; i++) left_rotate();
    }
    if(s[0]=='D'){
        if(s[1]=='+') down_rotate();
        if(s[1]=='-') for(int i=0; i<3; i++) down_rotate();
    }
}
int main(){
    cin>>t;
    while(t--){
        cube_raset();
        int n;
        cin>>n;
        for(int i=1; i<=n; i++){
            string s;
            cin>>s;
            go(s);
        }
        for(int k=0; k<3; k++){
            for(int j=0; j<3; j++){
                cout<<up[k][j];
            }
            cout<<'\n';
        }
    }
}
