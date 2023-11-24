#include <stdio.h>
#include <stdlib.h>

#define MEMORIA 100

struct memoria {
    char status;
    int inicio;
    int tamanho;
    int *prox;
};

void gerarMemoriaAleatoria(struct memoria *);
// void mostrarMemoria(struct memoria *);

int main () {
    struct memoria *mem = malloc(sizeof(struct memoria));
    mem->status = 'h';
    mem->inicio = 0;
    mem->tamanho = MEMORIA;
    mem->prox = NULL;

    gerarMemoriaAleatoria(mem);
    // mostrarMemoria(mem);

    free(mem);
}

void gerarMemoriaAleatoria(struct memoria *mem) {
    struct memoria *atual = mem;
    
    for(int i = 0; atual != NULL; i++) {
        float aleatorio = (float)rand() / RAND_MAX;

        atual->status = (aleatorio < 0.2) ? 'p' : 'h';

        if (atual->status == 'h') {
            atual->tamanho = rand() % 20 + 1;
        }

        if (atual->prox == NULL || atual->inicio + atual->tamanho != atual->prox->inicio ) {
            struct memoria *novo = malloc(sizeof(struct memoria));
            novo->prox = atual->prox;
            atual->prox = novo;
            novo->inicio = atual->inicio + atual->tamanho;
        }

        atual = atual->prox;
    }

}

