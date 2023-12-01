#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Memory
{
    int inicio;
    int tamanho;
    int espaco;
    struct Memory *prox;
};

struct Memory *criarMemoria(int, int, int);
void iniciarLista(struct Memory **, int, int, int);
void mostrarEspacos(struct Memory *);
void liberarMemorias(struct Memory *);
void unirMemorias(struct Memory *);
void simularEspacosMemoria(struct Memory **, int, int);
void mostrarMemoria(struct Memory *);
void firstFit(struct Memory **, int);

int main() {
    srand(time(NULL));

    int opcao;
    int tamanhoAdicionar;
    int tamanhoArmazenado;
    int tamanhoMax;
    struct Memory *head = NULL;

    printf("Insira o tamanho da memória espaço: ");
    scanf("%d", &tamanhoArmazenado);
    printf("Insira o tamanho máximo: ");
    scanf("%d", &tamanhoMax);
    simularEspacosMemoria(&head, tamanhoArmazenado, tamanhoMax);

    while (1) {
        puts("\nStatus:");
        mostrarMemoria(head);
        mostrarEspacos(head);
        printf("\n 1 - Inserir processos (First-Fit)\n 2 - Terminar\n");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            puts("Escolha feita - (First-Fit)");
            scanf("%d", &tamanhoAdicionar);
            firstFit(&head, tamanhoAdicionar);
            break;

        case 2:
            exit(0);
            break;

        default:
            puts("Insira um valor válido (1, 2 ou 3)\n");
            break;
        }
    }

    while (head != NULL) {
        struct Memory *temp = head;
        head = head->prox;
        free(temp);
    }

    return 0;
}

struct Memory *criarMemoria(int inicio, int tamanho, int espaco) {
    struct Memory *newMemory = (struct Memory *)malloc(sizeof(struct Memory));
    if (newMemory == NULL) {
        printf("Erro ao alocar a memória.\n");
        exit(1);
    }
    newMemory->inicio = inicio;
    newMemory->tamanho = tamanho;
    newMemory->espaco = espaco;
    newMemory->prox = NULL;
    return newMemory;
}

void iniciarLista(struct Memory **head, int inicio, int tamanho, int espaco) {
    struct Memory *newMemory = criarMemoria(inicio, tamanho, espaco);
    newMemory->prox = *head;
    *head = newMemory;
}


void mostrarEspacos(struct Memory *head) {
    while (head != NULL) {
        for (int x = head->tamanho; x != 0; x--) {
            if (head->espaco == 0) {
                printf("0");
            }
            else {
                printf("-");
            }
        }
        head = head->prox;
    }
    printf("\n");
}

void liberarMemorias(struct Memory *head) {
    while (head != NULL) {
        struct Memory *temp = head;
        head = head->prox;
        free(temp);
    }
}

void unirMemorias(struct Memory *head) {
    while (head != NULL && head->prox != NULL) {
        if (head->espaco == 1 && head->prox->espaco == 1) {
            head->tamanho += head->prox->tamanho;
            struct Memory *temp = head->prox;
            head->prox = head->prox->prox;
            free(temp);
        }
        else {
            head = head->prox;
        }
    }
}

void mostrarMemoria(struct Memory *head) {
    while (head != NULL) {
        printf("(%d, %d, %d)\n", head->inicio, head->tamanho, head->espaco);
        head = head->prox;
    }
    printf("NULL\n");
}

void simularEspacosMemoria(struct Memory **head, int tamanhoArmazenado, int tamanhoMax) {
    int espacoOcupado = 0;
    int espacoMapeado = tamanhoArmazenado;
    while (espacoOcupado < tamanhoArmazenado) {
        int tamanho = rand() % ((tamanhoArmazenado + 1) - espacoOcupado);
        if (tamanho == 0 || tamanho > tamanhoMax) continue;
        int espaco = rand() % 2;
        espacoMapeado -= tamanho;
        iniciarLista(head, espacoMapeado, tamanho, espaco);
        espacoOcupado += tamanho;
        printf("Local: %d\nespaco Adicionado: %d \nStatus do espaço: %d\n\n", espacoMapeado, tamanho, espaco);
    }

    unirMemorias(*head);
}

void firstFit(struct Memory **head, int tamanhoAdicionar) {
    if (*head == NULL) {
        return;
    }

    if ((*head)->espaco == 1 && (*head)->tamanho >= tamanhoAdicionar) {
        struct Memory *newMemory = criarMemoria((*head)->inicio, tamanhoAdicionar, 0);
        (*head)->inicio += tamanhoAdicionar;
        (*head)->tamanho -= tamanhoAdicionar;
        newMemory->prox = *head;
        *head = newMemory;
        return;
    }

    struct Memory *current = *head;

    while (current != NULL && current->prox != NULL) {
        if (current->prox->espaco == 1 && current->prox->tamanho >= tamanhoAdicionar) {
            struct Memory *newMemory = criarMemoria(current->prox->inicio, tamanhoAdicionar, 0);
            current->prox->inicio += tamanhoAdicionar;
            current->prox->tamanho -= tamanhoAdicionar;
            newMemory->prox = current->prox;
            current->prox = newMemory;
            return;
        }
        current = current->prox;
    }
}
