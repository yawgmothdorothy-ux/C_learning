#include<stdio.h>
#include<ctype.h>
int main(){
    int letter =0, blank =0, digit = 0 ,other=0;

    for(int i=0;i<10;i++){

        int ch = getchar();
        if (ch == EOF) {
            return 0;
        }

         if (isalpha(ch)) {
            letter++;
        } else if (ch == ' ' || ch == '\n') {
            blank++;
        } else if (isdigit(ch)) {
            digit++;
        } else {
            other++;
        }
    }
    printf("letter = %d, blank = %d, digit = %d, other = %d\n",letter,blank,digit,other);
    return 0;

}
