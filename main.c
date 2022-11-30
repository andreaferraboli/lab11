#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char **f;
    int n;
} testo;

void mostra(testo);

int carica(char *nf, testo *txt);

int main(int argc, char *argv[]) {
    testo temp;
    char *str[2] = {"pippo9", "pluto"};
    temp.f = str[0];
    temp.n = 2;
//    mostra(temp);
    carica("text.txt", &temp);
    mostra(temp);
    return 0;
}

void mostra(testo text) {
    int i;
    for (i = 0; i < text.n; ++i) {
        printf("%s", text.f[i]);
    }
}

int carica(char *nf, testo *txt) {
    printf("file:%s", nf);
    FILE *fp;
    if ((fp = fopen("text.txt", "r")) == NULL) {
        printf("Errore nell’apertura del file!");
        return -1;
    }
    int n_righe, i;
    fscanf(fp, "%d", &n_righe);
    printf("n_righe=%d \n",n_righe);
    if (n_righe <= 0)
        return -2;
    char **f = (char **) malloc(sizeof(BUFSIZ) * n_righe);
    for (i = 0; i <= n_righe; ++i) {
        fscanf(fp, "%s", f[i]);
    }
    txt->f = f;
    txt->n = n_righe;
    return 0;
}