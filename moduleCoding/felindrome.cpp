//#include <string.h>
//#include <cstring>
#include <stdio.h>

//strlen(str)
int user_strlen(char * str) {
    int cnt = 0;
    while(*str != '\0') {
        cnt++;
        str++;
    }
    return cnt;
}

//reverse
void user_strReverse(char * str) {
    char swap = 0;
    int len = user_strlen(str);
    for(int i = 0; i<len/2; i++) {
        swap = str[len-1];
        str[i] = str[len-1-i];
        str[len-1-i] = swap;
    }
    return;
}
//strcpy
void user_strcpy(char * dst, char * src) {
    while(*dst != '\0') {
        *dst = *src;
        src++;
        dst++;
    }
    *dst = '\0';
}

int user_strcmp(char * str1, char * str2) {
    int i = 0;
    while(str1[i] != '\0') {
        if(str1[i] != str2[i]) break;
        i++;
    }
    return (str1[i] - str2[i]);
    
}

int main(void) {
    char str1[] = "abcdef";
    char str2[] = "abcde";
    printf("%d", user_strcmp(str1, str2));
}