#include <stdio.h>
#include <stdlib.h>

void squeeze(char[], char[]);

int main()
{
    char s1[] = "asdfghjk";
    char s2[] = "adf";
    squeeze(s1, s2);
    printf("s1 is %s", s1);
    return 0;
}

void squeeze(char s1[], char s2[]){
    int i, j, k;
    k = 0;
    for(i = 0; s1[i] != '\0'; ++i){
        for(j = 0; s2[j] != '\0' && s2[j] != s1[i]; ++j);
        if(s2[j] == '\0'){
            s1[k++] = s1[i];
        }
    }
    s1[k] = '\0';
}
