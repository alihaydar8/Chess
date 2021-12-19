#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdbool.h>

typedef struct piece{
    int point ;
    char nom_piece;
    char color_piece;
}piece;

typedef struct Case{
    int x;
    int y;
}Case;

typedef struct tab_Case{
    Case *possibel;
    int num; 
}tab_Case;

piece **board;

void display_board(){
    printf("\t");
    for(int i=0;i<8;i++)printf("%d\t",i);
    printf("\n");
    for(int i=0;i<8;i++){
        printf("%d\t",i);
        for(int j=0;j<8;j++){
            if(board[i][j].color_piece == 'b'){
                printf("\x1B[31m");
                printf("%c\t",board[i][j].nom_piece); 
                printf("\x1B[0m");
            }
            else if(board[i][j].color_piece == 'n'){
                printf("\x1B[32m");
                printf("%c\t",board[i][j].nom_piece); 
                printf("\x1B[0m");
            }
            else{printf("%c\t",board[i][j].nom_piece);}  
            //   printf("%s\t",board[i][j].nom_piece);
        }
        printf("\n");
    }
}
void display_possibility(tab_Case tab_case){
    bool trouver = false;
    printf("\t");
    for(int i=0;i<8;i++)printf("%d\t",i);
    printf("\n");

    for(int i=0;i<8;i++){
        printf("%d\t",i);
        for(int j=0;j<8;j++){
            trouver = false;
            for(int k=0;k<tab_case.num;k++){
                if(i==tab_case.possibel[k].x && j==tab_case.possibel[k].y){
                    if(board[i][j].color_piece == 'b' || board[i][j].color_piece == 'n'){
                        printf("\x1B[33m");
                        printf("x\t"); 
                        printf("\x1B[0m");
                    }
                    else{
                        printf("x\t");
                    }
                    trouver = true;
                }
            }
        if(trouver == false){
            if(board[i][j].color_piece == 'b'){
                printf("\x1B[31m");
                printf("%c\t",board[i][j].nom_piece); 
                printf("\x1B[0m");
            }
            else if(board[i][j].color_piece == 'n'){
                printf("\x1B[32m");
                printf("%c\t",board[i][j].nom_piece); 
                printf("\x1B[0m");
            }
            else{printf("%c\t",board[i][j].nom_piece);}
        }
        }
        printf("\n");
    }

}
void initialisation(){

    for (int i=0;i<8;i++){
        board[i]=(piece*)malloc(8*sizeof(piece));
        for (int j=0;j<8;j++){
            if(i==1 || i==6){
                board[i][j].nom_piece ='P';
            }
            if( i== 2 || i==3 || i==4 || i==5 ){
                board[i][j].nom_piece ='-';
            }
            if(i == 7 || i == 0 ){
                if(j == 0 || j == 7){
                    board[i][j].nom_piece = 'T';
                }
                if(j == 1 || j == 6){
                    board[i][j].nom_piece = 'C';
                }
                if(j == 2 || j == 5){
                    board[i][j].nom_piece = 'F';
                }
                if(j == 3){
                    board[i][j].nom_piece = 'D';
                }
                if(j == 4){
                    board[i][j].nom_piece = 'R';
                }
            }
            if( i == 0 || i == 1){
                board[i][j].color_piece = 'b';
            }
            if( i == 6 || i == 7){
                board[i][j].color_piece = 'n';
            }
        }
    }
}

void deplace_piece(int x1 ,int y1, int x2, int y2){
    piece c;
    c = board[x1][y1];
    board[x1][y1] = board[x2][y2] ;
    board[x2][y2] = c ;
}

bool isEmpty(int x1 , int y1){
    if(board[x1][y1].nom_piece == '-') return true;
    else return false;
}

bool isPossible(int x1 ,int y1, int x2, int y2){
    if (board[x1][y1].color_piece == board[x2][y2].color_piece) return false;
    else return true;
}

tab_Case P_possibility(tab_Case tab_case,int x , int y){
    tab_case.possibel=(Case*)malloc(4*sizeof(Case));/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    tab_case.num=0;
    if(board[x][y].color_piece == 'b'){
        if(isEmpty(x+1,y) && x+1<8){
            tab_case.possibel[tab_case.num].x=x+1;
            tab_case.possibel[tab_case.num].y=y;
            tab_case.num++; 
        }
        if(x == 1 && isEmpty(x+2,y) ){
            tab_case.possibel[tab_case.num].x=x+2;
            tab_case.possibel[tab_case.num].y=y;
            tab_case.num++; 
        }
        if(board[x+1][y+1].color_piece == 'n' && x+1<8 && y+1<8){
            tab_case.possibel[tab_case.num].x=x+1;
            tab_case.possibel[tab_case.num].y=y+1;
            tab_case.num++;
        }
        if(board[x+1][y-1].color_piece == 'n' && x+1<8 && y-1>0){
            tab_case.possibel[tab_case.num].x=x+1;
            tab_case.possibel[tab_case.num].y=y-1;
            tab_case.num++;
        }
    }
    if(board[x][y].color_piece == 'n'){
        if(isEmpty(x-1,y) && x-1>0){
            tab_case.possibel[tab_case.num].x=x-1;
            tab_case.possibel[tab_case.num].y=y;
            tab_case.num++; 
        }
        if(x == 6 && isEmpty(x-2,y) ){
            tab_case.possibel[tab_case.num].x=x-2;
            tab_case.possibel[tab_case.num].y=y;
            tab_case.num++; 
        }
        if(board[x-1][y+1].color_piece == 'b' && x-1>0 && y+1<8){
            tab_case.possibel[tab_case.num].x=x-1;
            tab_case.possibel[tab_case.num].y=y+1;
            tab_case.num++;
        }
        if(board[x-1][y-1].color_piece == 'b' && x-1>0 && y-1>0){
            tab_case.possibel[tab_case.num].x=x-1;
            tab_case.possibel[tab_case.num].y=y-1;
            tab_case.num++;
        }
    }
    return tab_case;
}

tab_Case T_possibility(tab_Case tab_case,int x , int y){

    tab_case.possibel=(Case*)malloc(14*sizeof(Case));/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    tab_case.num=0;
    for (int i=x+1;i<8;i++){
        if( isEmpty(i,y) ){
            tab_case.possibel[tab_case.num].x=i;
            tab_case.possibel[tab_case.num].y=y;
            tab_case.num++;
        }
        else {
            if( isPossible(x,y,i,y) ){
                tab_case.possibel[tab_case.num].x=i;
                tab_case.possibel[tab_case.num].y=y;
                tab_case.num++; 
            }
            break;
        }
    }
    for (int i=x-1;i>=0;i--){
        if(isEmpty(i,y)){
            tab_case.possibel[tab_case.num].x=i;
            tab_case.possibel[tab_case.num].y=y;
            tab_case.num++;
        }
        else {
            if(isPossible(x,y,i,y) ){
                tab_case.possibel[tab_case.num].x=i;
                tab_case.possibel[tab_case.num].y=y;
                tab_case.num++; 
            }
            break;
        }
    }
    for (int i=y+1;i<8;i++){
        if(isEmpty(x,i)){
            tab_case.possibel[tab_case.num].x=x;
            tab_case.possibel[tab_case.num].y=i;
            tab_case.num++;
        }
        else {
            if(isPossible(x,y,x,i) ){
                tab_case.possibel[tab_case.num].x=x;
                tab_case.possibel[tab_case.num].y=i;
                tab_case.num++; 
            }
            break;
        }
    }
    for (int i=y-1;i>=0;i--){
        if(isEmpty(x,i)){
            tab_case.possibel[tab_case.num].x=x;
            tab_case.possibel[tab_case.num].y=i;
            tab_case.num++;
        }
        else {
            if(isPossible(x,y,x,i) ){
                tab_case.possibel[tab_case.num].x=x;
                tab_case.possibel[tab_case.num].y=i;
                tab_case.num++; 
            }
            break;
        }
    } 
    return tab_case;
}

tab_Case F_possibility(tab_Case tab_case,int x , int y){

    tab_case.possibel=(Case*)malloc(14*sizeof(Case));/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    tab_case.num=0;
    int j=y+1;
    for (int i=x+1;i<8;i++){
        if(j<8){
            if( isEmpty(i,j) ){
                tab_case.possibel[tab_case.num].x=i;
                tab_case.possibel[tab_case.num].y=j;
                tab_case.num++;
            }
            else {
                if( isPossible(x,y,i,j) ){
                    tab_case.possibel[tab_case.num].x=i;
                    tab_case.possibel[tab_case.num].y=j;
                    tab_case.num++; 
                }
                break;
            }
            j++;
        }
    }
    j=y+1;
    for (int i=x-1;i>=0;i--){
        if(j<8){
            if(isEmpty(i,j)){
                tab_case.possibel[tab_case.num].x=i;
                tab_case.possibel[tab_case.num].y=j;
                tab_case.num++;
            }
            else {
                if(isPossible(x,y,i,j) ){
                    tab_case.possibel[tab_case.num].x=i;
                    tab_case.possibel[tab_case.num].y=j;
                    tab_case.num++; 
                }
                break;
            }
            j++;
        }
    }
    j=y-1;
    for (int i=x+1;i<8;i++){
        if(j>=0){
            if(isEmpty(i,j)){
                tab_case.possibel[tab_case.num].x=i;
                tab_case.possibel[tab_case.num].y=j;
                tab_case.num++;
            }
            else {
                if(isPossible(x,y,i,j) ){
                    tab_case.possibel[tab_case.num].x=i;
                    tab_case.possibel[tab_case.num].y=j;
                    tab_case.num++; 
                }
                break;
            }
            j--;
        }
    }
    j=y-1;
    for (int i=x-1;i>=0;i--){
        if(j>=0){
            if(isEmpty(i,j)){
                tab_case.possibel[tab_case.num].x=i;
                tab_case.possibel[tab_case.num].y=j;
                tab_case.num++;
            }
            else {
                if(isPossible(x,y,i,j) ){
                    tab_case.possibel[tab_case.num].x=i;
                    tab_case.possibel[tab_case.num].y=j;
                    tab_case.num++; 
                }
                break;
            }
            j--;
        }
    } 
    return tab_case;

}
// void allPossibility(int x ,int y){}

int main (){
    board = (piece**)malloc(8*sizeof(piece));
    initialisation();
    // display_board();
    deplace_piece(0,0,3,3);
    deplace_piece(1,1,3,1);
    deplace_piece(7,7,3,5);
    deplace_piece(3,5,2,5);
    display_board();
    tab_Case tab_case = F_possibility(tab_case,6,4);
    // tab_case = T_possibility(tab_case,3,3);
    // for(int i=0;i<tab_case.num;i++){
    //     printf("%d,%d\n",tab_case.possibel[i].x,tab_case.possibel[i].y);
    // }
    printf("\n");
    display_possibility(tab_case);
    return 0;
}
