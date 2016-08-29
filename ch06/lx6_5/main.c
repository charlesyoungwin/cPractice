#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];

struct nlist{
    struct nlist *next;
    char *name;
    char *defn;
};

struct nlist *lookup(char *);
struct nlist *install(char *, char *);
struct nlist *undef(char *);

int main()
{

    return 0;
}

unsigned hash(char *s){
    unsigned hashval;
    for(hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s){
    struct nlist *np;
    for(np = hashtab[hash(s)]; np != NULL; np = np->next)
        if(strcmp(s, np->name) == 0)
            return np;
    return NULL;
}

struct nlist *lookup(char *);

struct nlist *install(char *name, char *defn){
    struct nlist *np;
    unsigned hashval;
    if((np = lookup(name)) == NULL){
        np = (struct nlist *) malloc(sizeof(* np));
        if(np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else
        free((void *) np->defn);
    if((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

struct nlist *undef(char *name){
    struct nlist *np, *pre;
    for(np = hashtab[hash(name)]; np != NULL; pre = np, np = np->next){
        if(strcmp(np->name, name) == 0)
            break;
    }
    pre->next = np->next;
    free(np);
}
