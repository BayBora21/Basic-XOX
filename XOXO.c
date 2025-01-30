#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int whowon(char mat[][3]){
    int i,j;
    for(i=0;i<3;i++){
        if((mat[i][0]=='X')&&(mat[i][1]=='X')&&(mat[i][2]=='X'))
            return 1;
    }
        for(i=0;i<3;i++){
        if((mat[0][i]=='X')&&(mat[1][i]=='X')&&(mat[2][i]=='X'))
            return 1;
    }
    if((mat[0][0]=='X')&&(mat[1][1]=='X')&&(mat[2][2]=='X'))
        return 1;
    if((mat[0][2]=='X')&&(mat[1][1]=='X')&&(mat[2][0]=='X'))
        return 1;

    for(i=0;i<3;i++){
        if((mat[i][0]=='O')&&(mat[i][2]=='O')&&(mat[i][2]=='O'))
            return 2;
    }
        for(i=0;i<3;i++){
        if((mat[0][i]=='O')&&(mat[2][i]=='O')&&(mat[2][i]=='O'))
            return 2;
    }
    if((mat[0][0]=='O')&&(mat[1][1]=='O')&&(mat[2][2]=='O'))
        return 2;
    if((mat[0][2]=='O')&&(mat[2][2]=='O')&&(mat[2][0]=='O'))
        return 2;
    else
        return 0;
}
void screenf(char mat[][3]){
    printf(" %c| %c |%c\n", mat[0][0], mat[0][1], mat[0][2]);
    printf("---------\n");
    printf(" %c| %c |%c\n", mat[1][0], mat[1][1], mat[1][2]);
    printf("---------\n");
    printf(" %c| %c |%c\n", mat[2][0], mat[2][1], mat[2][2]);
}

int checkpos(char mat[][3], int rposy, int rposx){
    if(mat[rposy][rposx]!=' ')
        return 1;
    else
        return 0;
}
void normal(char mat[][3]){
    int px=0, py=0;
    while(checkpos(mat,py,px)){
        px++;
        py++;
        printf("tring");
    }
    mat[py][px]='O';
}
int main(){
    srand(time(NULL));  
    int rposy=rand()%3;
    int rposx=rand()%3;
    int diff, posy, posx, i, j;
    char mat[3][3];
    printf("select difficulty (1-easy,2-medium,3-hard,4-impossible)");
    scanf(" %d", &diff);
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            mat[i][j] = ' ';
        }
    }
    screenf(mat);
    while(whowon(mat)==0){
        printf("your turn, row? ");
        scanf(" %d", &posy);
        printf("your turn, column? ");
        scanf(" %d", &posx);
        mat[posy-1][posx-1] = 'X';
        screenf(mat);
        printf("My turn!\n");
        if(checkpos(mat,rposy,rposx)){
            normal(mat);
            /*for(i=0;i<3;i++)
                rposy = i%3;
            for(j=0;j<3;j++)
                rposx = j%3;
            i++;*/
        }

        screenf(mat);
        printf("%d", whowon(mat));
    }
    
    }