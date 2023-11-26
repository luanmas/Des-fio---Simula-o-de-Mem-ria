#include <stdio.h>
#include <stdlib.h>

#define MEMORIA 100

struct memoria {
    char status;
    int inicio;
    int tamanho;
    struct memoria *prox;
};

void gerarMemoriaAleatoria(struct memoria *);
void mostrarMemoria(struct memoria *);

int main () {
    struct memoria *mem = malloc(sizeof(struct memoria));
    mem->status = 'h';
    mem->inicio = 0;
    mem->tamanho = MEMORIA;
    mem->prox = NULL;

    gerarMemoriaAleatoria(mem);
    mostrarMemoria(mem);

    free(mem);
}

void gerarMemoriaAleatoria(struct memoria *mem) {
    struct memoria *atual = mem;

    do {
        float aleatorio = (float)rand() / RAND_MAX;
        printf("Num : %.2f\n" , aleatorio);

        atual->status = (aleatorio < 0.2) ? 'p' : 'h';

        if (atual->status == 'h') {
            atual->tamanho = rand() % 21;
        }

        if (atual->prox == NULL || (atual->inicio + atual->tamanho != atual->prox->inicio)) {
            struct memoria *novo;
            novo = malloc(sizeof(struct memoria));
            novo->prox = atual->prox;
            atual->prox = novo;
            novo->inicio = (atual->inicio + atual->tamanho);
        }

        atual = atual->prox;
    } while(atual != NULL);
}

void mostrarMemoria(struct memoria * mem) {
    while (mem != NULL)  {
        printf("Tamanho da memória : %d , Status da memória : %c , Inicio : %d | Fim : %d\n" , mem->tamanho , mem->status , mem->inicio , (mem->inicio + mem->tamanho));
        mem = mem->prox;    
    }
}