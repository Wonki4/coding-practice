#include <stdio.h>


void strlwr(char str[]);
int main(void) {
    char str[11];
    // the size of string is made by considering the size of null(1) and the maximum value of integer (10)
    // After searching something about translate octal, hexdecimal, decimal into decimal interger, i can't find how to do it.
    // i decided to use the string.
    int i = 0;
    int sum = 0;
    int value = 0;
    int temp = 0;

    scanf("%s", str);
    // I made a function for lowering strings.
    strlwr(str);
    printf("%s\n", str);

    // i use the property that the first string is stored at the 0th array.
    if(str[0] == '0') {
        if(str[1] == 'x') {
            // In this case of hexdecimal
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
        //In this case of octal
        else {
            i = 1;
            sum = 0;
            while(str[i] != 0) {
                sum = sum * 8 + (int)(str[i]-'0');
                i += 1;
            }
        }
    }
    //In this case of decimal
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