#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define Pawn 'P'
#define Knight 'H'
#define Bishop 'B'
#define Rook 'R'
#define Queen 'Q'
#define King 'K'
#define White 'W'
#define Black 'b'

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

void display_player1_board(){
    printf("\t\x1B[33m");
    for(int i=0;i<8;i++)printf("%d\t",i);
    printf("\x1B[0m\n");
    for(int i=0;i<8;i++){
        printf("\x1B[33m%d\x1B[0m\t",i);
        for(int j=0;j<8;j++){
            if(board[i][j].color_piece == White){
                printf("\x1B[31m");
                printf("%c\t",board[i][j].nom_piece); 
                printf("\x1B[0m");
            }
            else if(board[i][j].color_piece == Black){
                printf("\x1B[32m");
                printf("%c\t",board[i][j].nom_piece); 
                printf("\x1B[0m");
            }
            else{
                printf("%c\t",board[i][j].nom_piece);
            }  
        }
        printf("\n");
    }
    printf("\n");
}

void display_player2_board(){
    printf("\t\x1B[33m");
    for(int i=0;i<8;i++)printf("%d\t",i);
    printf("\x1B[0m\n");
    for(int i=0;i<8;i++){
        printf("\x1B[33m%d\x1B[0m\t",i);
        for(int j=0;j<8;j++){
            if(board[7-i][j].color_piece == White){
                printf("\x1B[31m");
                printf("%c\t",board[7-i][j].nom_piece); 
                printf("\x1B[0m");
            }
            else if(board[7-i][j].color_piece == Black){
                printf("\x1B[32m");
                printf("%c\t",board[7-i][j].nom_piece); 
                printf("\x1B[0m");
            }
            else{
                printf("%c\t",board[7-i][j].nom_piece);
            }  
        }
        printf("\n");
    }
    printf("\n");
}

void display_player1_possibility(tab_Case tab_case){
    bool trouver = false;
    printf("\t\x1B[33m");
    for(int i=0;i<8;i++)printf("%d\t",i);
    printf("\x1B[0m\n");
    for(int i=0;i<8;i++){
       printf("\x1B[33m%d\x1B[0m\t",i);
        for(int j=0;j<8;j++){
            trouver = false;
            for(int k=0;k<tab_case.num;k++){
                if(i==tab_case.possibel[k].x && j==tab_case.possibel[k].y){
                    if(board[i][j].color_piece == White || board[i][j].color_piece == Black){
                        printf("\x1B[34m");
                        printf("x\t"); 
                        printf("\x1B[0m");
                    }
                    else{
                        printf("\x1B[33m");
                        printf("x\t"); 
                        printf("\x1B[0m");
                    }
                    trouver = true;
                }
            }
            if(trouver == false){
                if(board[i][j].color_piece == White){
                    printf("\x1B[31m");
                    printf("%c\t",board[i][j].nom_piece); 
                    printf("\x1B[0m");
                }
                else if(board[i][j].color_piece == Black){
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

void display_player2_possibility(tab_Case tab_case){
    bool trouver = false;
    printf("\t\x1B[33m");
    for(int i=0;i<8;i++)printf("%d\t",i);
    printf("\x1B[0m\n");
    for(int i=0;i<8;i++){
       printf("\x1B[33m%d\x1B[0m\t",i);
        for(int j=0;j<8;j++){
            trouver = false;
            for(int k=0;k<tab_case.num;k++){
                if(i==7-tab_case.possibel[k].x && j==tab_case.possibel[k].y){
                    if(board[7-i][j].color_piece == White || board[7-i][j].color_piece == Black){
                        printf("\x1B[34m");
                        printf("x\t"); 
                        printf("\x1B[0m");
                    }
                    else{
                        printf("\x1B[33m");
                        printf("x\t"); 
                        printf("\x1B[0m");
                    }
                    trouver = true;
                }
            }
            if(trouver == false){
                if(board[7-i][j].color_piece == White){
                    printf("\x1B[31m");
                    printf("%c\t",board[7-i][j].nom_piece); 
                    printf("\x1B[0m");
                }
                else if(board[7-i][j].color_piece == Black){
                    printf("\x1B[32m");
                    printf("%c\t",board[7-i][j].nom_piece); 
                    printf("\x1B[0m");
                }
                else{printf("%c\t",board[7-i][j].nom_piece);}
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
                board[i][j].nom_piece =Pawn;
            }
            if( i== 2 || i==3 || i==4 || i==5 ){
                board[i][j].nom_piece ='-';
            }
            if(i == 7 || i == 0 ){
                if(j == 0 || j == 7){
                    board[i][j].nom_piece = Rook;
                }
                if(j == 1 || j == 6){
                    board[i][j].nom_piece = Knight;
                }
                if(j == 2 || j == 5){
                    board[i][j].nom_piece = Bishop;
                }
                if(j == 3){
                    board[i][j].nom_piece = Queen;
                }
                if(j == 4){
                    board[i][j].nom_piece = King;
                }
            }
            if( i == 0 || i == 1){
                board[i][j].color_piece = White;
            }
            if( i == 6 || i == 7){
                board[i][j].color_piece = Black;
            }
        }
    }
}

bool condition_base(int x, int y){
    if(x <8 && x>=0 && y<8 && y>=0)return true;
    else return false;
}

bool isColor(char color ,int x,int y){
    if(condition_base(x,y) && board[x][y].color_piece == color) return true;
    else return false;
}

bool isPawn(int x,int y){
    if(condition_base(x,y) && board[x][y].nom_piece == Pawn) return true;
    else return false;
}

bool isRook(int x,int y){
    if(condition_base(x,y) && board[x][y].nom_piece == Rook) return true;
    else return false;
}

bool isBishop(int x,int y){
    if(condition_base(x,y) && board[x][y].nom_piece == Bishop) return true;
    else return false;
}

bool isKnight(int x,int y){
    if(condition_base(x,y) && board[x][y].nom_piece == Knight) return true;
    else return false;
}

bool isQueen(int x,int y){
    if(condition_base(x,y) && board[x][y].nom_piece == Queen) return true;
    else return false;
}

bool isKingColor(char color,int x,int y){
    if(condition_base(x,y) && board[x][y].nom_piece == King && board[x][y].color_piece == color) return true;
    else return false;
}

bool isEmpty(int x , int y){
    if(condition_base(x,y)){
        if(board[x][y].nom_piece == '-') return true;
        else return false;
    }
    else return false;
    
}

bool isPossible(int x1 ,int y1, int x2, int y2){
    if(condition_base(x1,y1) && condition_base(x2,y2)){
        if (board[x1][y1].color_piece == board[x2][y2].color_piece) return false;
        else return true;
    }
    else return false; 
}

void transformepPawn(int x , int y){
    int choix = 0 ;
    printf("\x1B[33mChoisir la piece pour transformer le pawn\n");
    printf("1 pour Queen\n");
    printf("2 pour Knight\n");
    printf("3 pour Bishop\n");
    printf("4 pour Rook\x1B[0m\n");
    scanf("%d",&choix);
    switch (choix){
        case 1 :
            board[x][y].nom_piece = Queen ;
            break;
        case 2 :
            board[x][y].nom_piece = Knight ;
            break;
        case 3 :
            board[x][y].nom_piece = Bishop ;
            break;
        case 4 :
            board[x][y].nom_piece = Rook ;
            break;
        default :
            board[x][y].nom_piece = Queen ;
            break;
    }
}

void deplace_piece(int x1 ,int y1, int x2, int y2){
    if(condition_base(x1,y1) && condition_base(x2,y2)){
        board[x2][y2] = board[x1][y1] ;
        board[x1][y1].nom_piece = '-';
        board[x1][y1].color_piece = ' ';
        if( (x2 == 0 || x2 == 7) && isPawn(x2,y2) ){
            transformepPawn(x2,y2);   
        }
    }
}

// tab_Case remplire_tab_Case(tab_Case tab_case,int num,int x,int y)
// {
//     tab_case.possibel[tab_case.num].x=x+1;
//     tab_case.possibel[tab_case.num].y=y;
//     return tab_case;
// }

tab_Case P_possibility(int x , int y){
    tab_Case tab_case;
    tab_case.possibel=(Case*)malloc(4*sizeof(Case));/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    tab_case.num=0;
    if(isColor(White,x,y)){
        if(isEmpty(x+1,y)){
            tab_case.possibel[tab_case.num].x=x+1;
            tab_case.possibel[tab_case.num].y=y;
            tab_case.num++; 
        }
        if(x == 1 && isEmpty(x+2,y) ){
            tab_case.possibel[tab_case.num].x=x+2;
            tab_case.possibel[tab_case.num].y=y;
            tab_case.num++; 
        }
        if(isColor(Black,x+1,y+1)){
            tab_case.possibel[tab_case.num].x=x+1;
            tab_case.possibel[tab_case.num].y=y+1;
            tab_case.num++;
        }
        if(isColor(Black,x+1,y-1)){
            tab_case.possibel[tab_case.num].x=x+1;
            tab_case.possibel[tab_case.num].y=y-1;
            tab_case.num++;
        }
    }
    if(isColor(Black,x,y)){
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
        if(isColor(White,x-1,y+1)){
            tab_case.possibel[tab_case.num].x=x-1;
            tab_case.possibel[tab_case.num].y=y+1;
            tab_case.num++;
        }
        if(isColor(White,x-1,y-1)){
            tab_case.possibel[tab_case.num].x=x-1;
            tab_case.possibel[tab_case.num].y=y-1;
            tab_case.num++;
        }
    }
    return tab_case;
}

tab_Case R_possibility(int x , int y){
    tab_Case tab_case;
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

tab_Case K_possibility(int x , int y){
    tab_Case tab_case;  
    tab_case.possibel=(Case*)malloc(8*sizeof(Case));/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    tab_case.num=0;
    if(isPossible(x,y,x+2,y+1)){
        tab_case.possibel[tab_case.num].x=x+2;
        tab_case.possibel[tab_case.num].y=y+1;
        tab_case.num++; 
    }
    if(isPossible(x,y,x+2,y-1)){
        tab_case.possibel[tab_case.num].x=x+2;
        tab_case.possibel[tab_case.num].y=y-1;
        tab_case.num++; 
    }
    if(isPossible(x,y,x+1,y+2) ){
        tab_case.possibel[tab_case.num].x=x+1;
        tab_case.possibel[tab_case.num].y=y+2;
        tab_case.num++; 
    }
    if(isPossible(x,y,x+1,y-2)){
        tab_case.possibel[tab_case.num].x=x+1;
        tab_case.possibel[tab_case.num].y=y-2;
        tab_case.num++; 
    }
    if(isPossible(x,y,x-2,y+1) ){
        tab_case.possibel[tab_case.num].x=x-2;
        tab_case.possibel[tab_case.num].y=y+1;
        tab_case.num++; 
    }
    if(isPossible(x,y,x-2,y-1)){
        tab_case.possibel[tab_case.num].x=x-2;
        tab_case.possibel[tab_case.num].y=y-1;
        tab_case.num++; 
    }
    if(isPossible(x,y,x-1,y+2)){
        tab_case.possibel[tab_case.num].x=x-1;
        tab_case.possibel[tab_case.num].y=y+2;
        tab_case.num++; 
    }
    if(isPossible(x,y,x-1,y-2)){
        tab_case.possibel[tab_case.num].x=x-1;
        tab_case.possibel[tab_case.num].y=y-2;
        tab_case.num++; 
    }
    return tab_case;
}

tab_Case B_possibility(int x , int y){
    tab_Case tab_case;
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

tab_Case ajouter_tab_Case(tab_Case tab_case1,tab_Case tab_case2){
    int num1 = tab_case1.num ;
    int num2 = tab_case2.num ;
    int num = num1 + num2 ;
    tab_Case tab_case ;
    tab_case.possibel=(Case*)malloc(num*sizeof(Case));
    tab_case = tab_case1 ;
    for(int i=0; i<num2;i++){
        tab_case.possibel[tab_case1.num+i]=tab_case2.possibel[i];
    }
    tab_case.num=num;
    return tab_case;
}

tab_Case Q_possibility(int x , int y){
    return ajouter_tab_Case(B_possibility(x,y),R_possibility(x,y));
}
//revoire ca
tab_Case allPossibility(char color){
    tab_Case tab_case;
    tab_case.possibel =(Case*)malloc(sizeof(Case));
    tab_case.num=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j].color_piece == color){
                if(isPawn(i,j)){
                    tab_case =  ajouter_tab_Case(tab_case,P_possibility(i,j));
                }
                if(isBishop(i,j)){
                    tab_case =  ajouter_tab_Case(tab_case,B_possibility(i,j));
                }
                if(isKnight(i,j)){
                    tab_case =  ajouter_tab_Case(tab_case,K_possibility(i,j));
                }
                if(isRook(i,j)){
                    tab_case =  ajouter_tab_Case(tab_case,R_possibility(i,j));
                }
                if(isQueen(i,j)){
                    tab_case =  ajouter_tab_Case(tab_case,Q_possibility(i,j));
                }
                //penser aa ajouter le roi
            }
        }
    }
    for(int i=0;i<tab_case.num;i++){
        for(int j=i+1;j<tab_case.num;j++){
            if(tab_case.possibel[i].x == tab_case.possibel[j].x && tab_case.possibel[i].y == tab_case.possibel[j].y){
                tab_case.possibel[j].x=100;
                tab_case.possibel[j].y=100;
            }
        }
    }
    return tab_case;
}
//
bool isCase_appartient_tab_Case(tab_Case tab_case,int x,int y){
    if(condition_base(x,y)){
        for(int i=0;i<tab_case.num;i++){
            if(tab_case.possibel[i].x == x && tab_case.possibel[i].y==y)
                return true;
        }
    }
    return false;
}

tab_Case King_possibility(int x ,int y){
    tab_Case tab_case;
    tab_case.possibel=(Case*)malloc(8*sizeof(Case));/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    tab_case.num=0;
    char color = Black;
    if(isColor(Black,x,y)){
        color =White;
    }
    if(!isCase_appartient_tab_Case(allPossibility(color),x,y+1) && isPossible(x,y,x,y+1) && !isKingColor(color,x,y+2) && !isKingColor(color,x+1,y+2) && !isKingColor(color,x-1,y+2) ){
        tab_case.possibel[tab_case.num].x=x;
        tab_case.possibel[tab_case.num].y=y+1;
        tab_case.num++; 
    }
    if(!isCase_appartient_tab_Case(allPossibility(color),x,y-1) && isPossible(x,y,x,y-1) && !isKingColor(color,x,y-2) && !isKingColor(color,x+1,y-2) && !isKingColor(color,x-1,y-2) ){
        tab_case.possibel[tab_case.num].x=x;
        tab_case.possibel[tab_case.num].y=y-1;
        tab_case.num++; 
    }
    if(!isCase_appartient_tab_Case(allPossibility(color),x+1,y) && isPossible(x,y,x+1,y) && !isKingColor(color,x+2,y) && !isKingColor(color,x+2,y+1) && !isKingColor(color,x+2,y-1) ){
        tab_case.possibel[tab_case.num].x=x+1;
        tab_case.possibel[tab_case.num].y=y;
        tab_case.num++; 
    }
    if(!isCase_appartient_tab_Case(allPossibility(color),x-1,y) && isPossible(x,y,x-1,y) && !isKingColor(color,x-2,y) && !isKingColor(color,x-2,y+1) && !isKingColor(color,x-2,y-1)){
        tab_case.possibel[tab_case.num].x=x-1;
        tab_case.possibel[tab_case.num].y=y;
        tab_case.num++; 
    }
    if(!isCase_appartient_tab_Case(allPossibility(color),x+1,y+1) && isPossible(x,y,x+1,y+1) && !isKingColor(color,x,y+2) && !isKingColor(color,x+1,y+2) && !isKingColor(color,x+2,y+2) && !isKingColor(color,x+2,y+1) && !isKingColor(color,x+2,y) ){
        tab_case.possibel[tab_case.num].x=x+1;
        tab_case.possibel[tab_case.num].y=y+1;
        tab_case.num++; 
    }
    if(!isCase_appartient_tab_Case(allPossibility(color),x-1,y-1) && isPossible(x,y,x-1,y-1) && !isKingColor(color,x,y-2) && !isKingColor(color,x-1,y-2) && !isKingColor(color,x-2,y-2) && !isKingColor(color,x-2,y-1) && !isKingColor(color,x-2,y) ){
        tab_case.possibel[tab_case.num].x=x-1;
        tab_case.possibel[tab_case.num].y=y-1;
        tab_case.num++; 
    }
    if(!isCase_appartient_tab_Case(allPossibility(color),x+1,y-1) && isPossible(x,y,x+1,y-1) && !isKingColor(color,x+2,y) && !isKingColor(color,x+2,y-1) && !isKingColor(color,x+2,y-2) && !isKingColor(color,x+1,y-2) && !isKingColor(color,x,y-2) ){
        tab_case.possibel[tab_case.num].x=x+1;
        tab_case.possibel[tab_case.num].y=y-1;
        tab_case.num++; 
    }
    if(!isCase_appartient_tab_Case(allPossibility(color),x-1,y+1) && isPossible(x,y,x-1,y+1) && !isKingColor(color,x,y+2) && !isKingColor(color,x-1,y+2) && !isKingColor(color,x-2,y+2) && !isKingColor(color,x-2,y+1) && !isKingColor(color,x-2,y) ){
        tab_case.possibel[tab_case.num].x=x-1;
        tab_case.possibel[tab_case.num].y=y+1;
        tab_case.num++; 
    }
    return tab_case;
}

tab_Case possibility(int x,int y){
    switch (board[x][y].nom_piece){
        case Pawn : 
            return P_possibility(x,y);
        case Rook :
            return R_possibility(x,y);
        case Knight :
            return K_possibility(x,y);
        case King :
            return King_possibility(x,y);
        case Queen :
            return Q_possibility(x,y);
        case Bishop :
            return B_possibility(x,y);
        default :
            printf("il y a pas de pieace");
            break;
    }
}  

int choisirPiecePossibiltyPlayer1(){
    int choix0 ;
    do{
        printf("\x1B[31mchoisie la piece pour voir les possibility\n\x1B[0m");
        scanf("%d",&choix0);
        if(isEmpty(choix0/10,choix0%10)){
            printf("\x1B[31mil y a pas de piece\n\x1B[0m");
        }
    }while(isEmpty(choix0/10,choix0%10) || isColor(Black,choix0/10,choix0%10));
    display_player1_possibility(possibility(choix0/10,choix0%10));
    return choix0;
}

int choisirPiecePossibiltyPlayer2(){
    int choix0 ;
    do{
        printf("\x1B[32mchoisie la piece pour voir les possibility\n\x1B[0m");
        scanf("%d",&choix0);
        if(isEmpty(7-choix0/10,choix0%10)){
            printf("\x1B[32mil y a pas de piece\n\x1B[0m");
        }
    }while(isEmpty(7-choix0/10,choix0%10) || isColor(White,7-choix0/10,choix0%10));
    display_player2_possibility(possibility(7-(choix0/10),choix0%10));
    return choix0;
}

int main (){
    int choix0 ;
    int choix1 ;
    board = (piece**)malloc(8*sizeof(piece));
    initialisation();
    while(true){
        
        display_player1_board();
        choix0 = choisirPiecePossibiltyPlayer1();
        do{
            printf("\x1B[31mchoisie ou placer la piece ou 99 pour choisir une autre piece pour voir les possibility \x1B[0m");
            scanf("%d",&choix1);
            if(choix1 == 99 ){
                choix0 = choisirPiecePossibiltyPlayer1();
            }
            else if(!isCase_appartient_tab_Case(possibility(choix0/10,choix0%10),choix1/10,choix1%10)){
                printf("\x1B[31melle peut pas partir si loin\n\x1B[0m ");
            }
        }while(!isCase_appartient_tab_Case(possibility(choix0/10,choix0%10),choix1/10,choix1%10) || choix1 == 99 );
        deplace_piece(choix0/10,choix0%10,choix1/10,choix1%10);

        display_player2_board();
        choix0 = choisirPiecePossibiltyPlayer2();
        do{
            printf("\x1B[32mchoisie ou placer la piece ou 99 pour choisir une autre piece pour voir les possibility\x1B[0m ");
            scanf("%d",&choix1);
            if(choix1 == 99 ){
                choix0 = choisirPiecePossibiltyPlayer2();
            }
            else if(!isCase_appartient_tab_Case(possibility(7-(choix0/10),choix0%10),7-(choix1/10),choix1%10)){
                printf("\x1B[32melle peut pas partir si loin\n\x1B[0m ");
            }
        }while(!isCase_appartient_tab_Case(possibility(7-(choix0/10),choix0%10),7-(choix1/10),choix1%10));
        deplace_piece(7-(choix0/10),choix0%10,7-(choix1/10),choix1%10);
    }
    
    return 0;
}

