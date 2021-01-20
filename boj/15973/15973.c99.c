#include <stdio.h>

struct date{
    int x1,y1,x2,y2;
}p,q;
int main(){
    scanf("%d %d %d %d",&p.x1,&p.y1,&p.x2,&p.y2);
    scanf("%d %d %d %d",&q.x1,&q.y1,&q.x2,&q.y2);
    if(p.x1>q.x2||q.x1>p.x2||p.y1>q.y2|q.y1>p.y2){
        printf("NULL\n");
    }
    else if((p.x1==q.x2||p.x2==q.x1)&&(q.y1==p.y2||q.y2==p.y1)){
        printf("POINT\n");
    }
    else if(p.x1==q.x2||p.x2==q.x1||p.y1==q.y2||p.y2==q.y1){
        printf("LINE\n");
    }
    else printf("FACE\n");
}