#include <stdio.h>
#include <stdlib.h>
#include "string.h"
typedef struct {
    char **f;
    int n;
} testo;

void mostra(testo);

int carica(char *nf, testo *txt);

int main(int argc, char *argv[]) {
    testo temp;
    char *str[2] = {"pippo9", "pluto"};
    temp.f = str;
    temp.n = 2;
//    mostra(temp);
    carica(argv[1], &temp);
    mostra(temp);
    return 0;
}

void mostra(testo text) {
    int i;
    for (i = 0; i < text.n; ++i) {
        printf("stringa[i]=%s", text.f[i]);
    }
}

int carica(char *nf, testo *txt) {
    printf("file:%s \n", nf);
    FILE *fp;
    if ((fp = fopen(nf, "r")) == NULL) {
        printf("Errore nell’apertura del file!");
        return -1;
    }
    int n_righe, i=0;
    fscanf(fp, "%d%*c", &n_righe);
    printf("n_righe=%d \n",n_righe);
    if (n_righe <= 0)
        return -2;
    char **f = (char **) malloc(BUFSIZ * n_righe);
    char *res;
    while (!feof(fp)) {
        printf("i=%d",i);
        fgets(res,100,fp);
        char str[strlen(res)];
        strcpy(str,res);
        strcpy(f[i],str);
        printf("f[i]=%s \n", f[i++]);
    }
    txt->f = f;
    txt->n = n_righe;
    return 0;
}