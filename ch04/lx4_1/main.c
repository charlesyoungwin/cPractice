#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main()
{
    char line[MAXLINE];
    int found = 0;
    int n;
    while(getline(line, MAXLINE) > 0){
        if((n = strindex2(line, pattern)) >= 0){
            printf("%s", line);
            printf("%d", n);
            found++;
        }
    }
    return found;
}

int getline(char s[], int lim){
    int c, i;
    i = 0;
    while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if(c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int strindex(char s[], char t[]){
    int i, j, k;
    int pos = -1;
    for(i = 0; s[i] != '\0'; i++){
        for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if(k > 0 && t[k] == '\0'){
            if(i > pos)
                pos = i;
        }
    }
    return pos;
}

int strindex2(char s[], char t[]){
    int i, j, k;
    for(i = strlen(s) - strlen(t); i > 0; i--){
        for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if(k > 0 && t[k] == '\0'){
            return i;
        }
    }
    return -1;
}
