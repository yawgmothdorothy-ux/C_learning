#include<stdio.h>

int main(){
    int m,n;
    scanf("%d %d",&m,&n);

    int piece[m][n] ;

    char input_piece;

    for (int i=0;i<m;i++){
        for (int j =0;j<n;j++){

            scanf(" %c",&input_piece);

            if (input_piece == '#'){
                piece[i][j] = 2;
            }else{
                piece[i][j] = -3;
            }
        }
    }

    int k;

    int x,y;

    scanf("%d",&k);
    for(int i =0;i<k;i++){
        int count = 0;
        scanf("%d %d",&x,&y);
            piece[x][y] -= 2;
            if (piece[x][y] == 0||piece[x][y] == -1){
                piece[x][y] = -3;
                count ++;
            }
            if (x+1<m){
                piece[x+1][y] -= 1;
                if(piece[x+1][y] == 0||piece [x+1][y]== -1){
                    piece[x+1][y] = -3;
                    count ++;
                }
            }
            if (x-1>=0){
                piece[x-1][y] -= 1;
                if(piece[x-1][y] == 0||piece [x-1][y]== -1){
                     piece[x-1][y] = -3;
                    count ++;
                }
            }
            if (y-1>=0){
                piece[x][y-1] -= 1;
                if(piece[x][y-1] == 0||piece [x][y-1]== -1){
                     piece[x][y-1] = -3;
                    count ++;
                }
            }
              if (y+1<n){
                piece[x][y+1] -= 1;
                if(piece[x][y+1] == 0||piece [x][y+1]== -1){
                     piece[x][y+1] = -3;
                    count ++;
                }
            }
            printf("%d\n",count);
    }
}