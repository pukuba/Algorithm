/*
 두점 사이의 거리
 3점의좌표로 정사각형
 nCr
 배열
 자료구조 vector
 그래프 dfs/bfs or stl
 */

#include<stdio.h>
#include<math.h>
int main(){
    int x1,x2,x3,y1,y2,y3,xa,ya;
    scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
    if(x1==x2) xa=x3;
    if(x2==x3) xa=x1;
    if(x1==x3) xa=x2;
    if(y1==y2) ya=y3;
    if(y2==y3) ya=y1;
    if(y1==y3) ya=y2;
    printf("%d %d",xa,ya);
        
}
