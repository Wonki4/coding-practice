#include <stdio.h>
void strlwr(char str[]);
int main(void) {
    char str[11];
    int i = 0;
    int sum = 0;
    int value = 0;
    int temp = 0;

    scanf("%s", str);
    strlwr(str);
    printf("%s\n", str);
    if(str[0] == '0') {
        if(str[1] == 'x') {
            i = 2;
            sum = 0;
            while(str[i] != 0) {
                temp = 0;
                if(str[i] >= 'a' && str[i] <= 'f' ) {
                    temp = str[i] - 'a' + 10;
                }
                else temp = (int)(str[i] - '0');
                sum = sum * 16 + (int)temp;
                i += 1;
            }
        }
        else {
            i = 1;
            sum = 0;
            while(str[i] != 0) {
                sum = sum * 8 + (int)(str[i]-'0');
                i += 1;
            }
        }
    }
    else {
        i = 0;
        sum = 0;
        while(str[i] != 0) {
            sum = sum * 10 + (int)(str[i]-'0');
            i += 1;
        }
    }
    printf("%d\n", sum);


    return 0;
}

void strlwr(char str[]){
    int i=0;
    while(str[i]){
        if(str[i]>='A' && str[i]<='Z'){
            str[i]=str[i]+32;
        }       
        i++;
    }
}