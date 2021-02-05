#include <bits/stdc++.h>

using namespace std;
int map_size_y,map_size_x,monster_count,box_count,start_y,start_x,game_turn;
char rpg_map[103][103];
string character_move;
struct monster{
    int monster_y,monster_x,atk_point,def_point,hp_point,exp_information,max_hp;
    string monster_name;
}monster_info[103][103];
struct item_box{
    int item_box_y,item_box_x;
    char item_type;
    string item_information;
}box_info[103][103];
struct character{
    int pos_y,pos_x,exp,hp,max_hp,acc_count,level,sword_up,armor_up,exp_max,atk_point,def_point;
    bool hr,re,co,ex,dx,hu,cu;
}hero;
bool in(int here_y,int here_x){
    return 1<=here_y && here_y<=map_size_y && 1<=here_x && here_x<=map_size_x && rpg_map[here_y][here_x]!='#';
}
void acc_equip(string info){
    if(info == "HR"){
        if(hero.acc_count >= 4 || hero.hr) return;
        hero.hr = true;
        hero.acc_count++;
    }
    if(info == "RE"){
        if(hero.acc_count >= 4 || hero.re) return;
        hero.re = true;
        hero.acc_count++;
    }
    if(info == "CO"){
        if(hero.acc_count >= 4 || hero.co) return;
        hero.co = true;
        hero.acc_count++;
    }
    if(info == "EX"){
        if(hero.acc_count >= 4 || hero.ex) return;
        hero.ex = true;
        hero.acc_count++;
    }
    if(info == "DX"){
        if(hero.acc_count >= 4 || hero.dx) return;
        hero.dx = true;
        hero.acc_count++;
    }
    if(info == "HU"){
        if(hero.acc_count >= 4 || hero.hu) return;
        hero.hu = true;
        hero.acc_count++;
    }
    if(info == "CU"){
        if(hero.acc_count >= 4 || hero.cu) return;
        hero.cu = true;
        hero.acc_count++;
    }
}
void end_game(){
    for(int i=1; i<=map_size_y; i++){
        for(int j=1; j<=map_size_x; j++){
            cout<<rpg_map[i][j];
        }
        cout<<'\n';
    }
    cout<<"Passed Turns : "<<game_turn<<'\n';
    cout<<"LV : "<<hero.level<<'\n';
    cout<<"HP : "<<hero.hp<<"/"<<hero.max_hp<<'\n';
    cout<<"ATT : "<<hero.atk_point<<"+"<<hero.sword_up<<'\n';
    cout<<"DEF : "<<hero.def_point<<"+"<<hero.armor_up<<'\n';
    cout<<"EXP : "<<hero.exp<<"/"<<hero.exp_max<<'\n';
}
void char_move(char move_point){
    int cur_char_x = hero.pos_x,cur_char_y = hero.pos_y;
    if(move_point == 'R'){
        cur_char_x+=1;
        if(!in(cur_char_y,cur_char_x)) return ;
        hero.pos_x = cur_char_x;
        return ;
    }
    if(move_point == 'L'){
        cur_char_x-=1;
        if(!in(cur_char_y,cur_char_x)) return ;
        hero.pos_x = cur_char_x;
        return ;
    }
    if(move_point == 'D'){
        cur_char_y+=1;
        if(!in(cur_char_y,cur_char_x)) return ;
        hero.pos_y = cur_char_y;
        return ;
    }
    if(move_point == 'U'){
        cur_char_y-=1;
        if(!in(cur_char_y,cur_char_x)) return ;
        hero.pos_y = cur_char_y;
        return ;
    }
}
void open_box(){
    int cur_y = hero.pos_y;
    int cur_x = hero.pos_x;
    if(box_info[cur_y][cur_x].item_type == 'W'){
        int status = stoi(box_info[cur_y][cur_x].item_information);
        hero.sword_up = status;
        return ;
    }
    if(box_info[cur_y][cur_x].item_type == 'A'){
        int status = stoi(box_info[cur_y][cur_x].item_information);
        hero.armor_up = status;
        return ;
    }
    if(box_info[cur_y][cur_x].item_type == 'O'){
        string acc_type = box_info[cur_y][cur_x].item_information;
        acc_equip(acc_type);
    }
}
void update_hero(){
    if(hero.exp>=hero.exp_max){
        hero.exp=0;
        hero.exp_max+=5;
        hero.level+=1;
        hero.max_hp+=5;
        hero.hp = hero.max_hp;
        hero.atk_point+=2;
        hero.def_point+=2;
    }
}
void spike(){
    if(hero.dx) hero.hp-=1;
    else hero.hp-=5;
    if(hero.hp <= 0) {
        if(hero.re){
            hero.re=false;
            hero.pos_x = start_x;
            hero.pos_y = start_y;
            hero.hp = hero.max_hp;
            return ;
        }
        else{
            hero.hp=0;
            end_game();
            cout<<"YOU HAVE BEEN KILLED BY SPIKE TRAP..\n";
            exit(0);
        }
    }
}
void fight(){
    monster &villain = monster_info[hero.pos_y][hero.pos_x];
    bool critical = false;
    bool miss = false;
    while(1<=hero.hp && 1<=villain.hp_point){
        if(critical == false){
            critical = true;
            if(hero.dx && hero.co){
                villain.hp_point -= max(1,((hero.atk_point + hero.sword_up)*3)-villain.def_point);
            }
            else if(hero.co){
                villain.hp_point -= max(1,((hero.atk_point + hero.sword_up)*2)-villain.def_point);
            }
            else villain.hp_point -= max(1,(hero.atk_point + hero.sword_up)-villain.def_point);
        }
        else{
            villain.hp_point -= max(1,(hero.atk_point + hero.sword_up)-villain.def_point);
        }
        if(villain.hp_point<=0){
            rpg_map[hero.pos_y][hero.pos_x] = '.';
            if(hero.ex) hero.exp+=(villain.exp_information)*1.2;
            else hero.exp+=villain.exp_information;
            if(hero.hr) hero.hp = min(hero.hp+3,hero.max_hp);
            return ;
        }
        if(miss == false && rpg_map[hero.pos_y][hero.pos_x] == 'M'){
            miss = true;
            if(hero.hu) continue;
            hero.hp -= max(1, (villain.atk_point -(hero.def_point + hero.armor_up)));
        }
        else{
            hero.hp -= max(1,(villain.atk_point -(hero.def_point + hero.armor_up)));
        }
    }
    if(hero.re){
        hero.re = false;
        hero.hp=hero.max_hp;
        villain.hp_point = villain.max_hp;
        hero.pos_x = start_x;
        hero.pos_y = start_y;
    }
    else{
        hero.hp=0;
        end_game();
        cout<<"YOU HAVE BEEN KILLED BY "<<villain.monster_name<<".."<<'\n';
        exit(0);
    }
}
void event(){
    int cur_y = hero.pos_y;
    int cur_x = hero.pos_x;
    if(rpg_map[cur_y][cur_x] == 'B'){
        open_box();
        rpg_map[cur_y][cur_x]='.';
        return ;
    }
    if(rpg_map[cur_y][cur_x] == '&'){
        fight();
    }
    if(rpg_map[cur_y][cur_x] == 'M'){
        if(hero.hu) hero.hp = hero.max_hp;
        fight();
        if(rpg_map[cur_y][cur_x] =='.'){
            update_hero();
            rpg_map[cur_y][cur_x] = '@';
            end_game();
            cout<<"YOU WIN!"<<'\n';
            exit(0);
        }
    }
    if(rpg_map[cur_y][cur_x] == '.') return ;
    if(rpg_map[cur_y][cur_x] == '^'){
        spike();
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>map_size_y>>map_size_x;
    for(int i=1; i<=map_size_y; i++){
        for(int j=1; j<=map_size_x; j++){
            cin>>rpg_map[i][j];
            if(rpg_map[i][j] == 'M' || rpg_map[i][j] == '&') monster_count++;
            if(rpg_map[i][j] == 'B') box_count++;
            if(rpg_map[i][j] == '@'){
                rpg_map[i][j]='.';
                start_y = i;
                start_x = j;
                hero={i,j,0,20,20,0,1,0,0,5,2,2,0,0,0,0,0,0};
            }
        }
    }
    cin>>character_move;
    for(int i=1; i<=monster_count; i++){
        int info_y,info_x,atk,def,hp,exp;
        string info_name;
        cin>>info_y>>info_x>>info_name>>atk>>def>>hp>>exp;
        monster_info[info_y][info_x]={info_y,info_x,atk,def,hp,exp,hp,info_name};
    }
    for(int i=1; i<=box_count; i++){
        int info_y,info_x;
        char item_code;
        string info;
        cin>>info_y>>info_x>>item_code>>info;
        box_info[info_y][info_x]={info_y,info_x,item_code,info};
    }
    for(int i=0; i<character_move.size(); i++){
        game_turn++;
        char_move(character_move[i]);
        event();
        update_hero();
    }
    rpg_map[hero.pos_y][hero.pos_x] = '@';
    end_game();
    cout<<"Press any key to continue.\n";
}
