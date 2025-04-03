#include <stdio.h>

int vetor[50]; 
int tamanho;

void mostrarMenu() {
    printf("\n--- MENU ---\n");
    printf("1. Mostrar vetor\n");
    printf("2. Procurar numero\n");
    printf("3. Apagar numero\n");
    printf("4. Adicionar numero\n");
    printf("5. Sair\n");
    printf("Escolha: ");
}

void adicionarOrdenado(int valor) {
    if(tamanho >= 50) {
        printf("Vetor cheio!\n");
        return;
    }
    
    int pos = tamanho;
    while(pos > 0 && vetor[pos-1] > valor) {
        vetor[pos] = vetor[pos-1];
        pos--;
    }
    vetor[pos] = valor;
    tamanho++;
}

int buscar(int valor) {
    int inicio = 0, fim = tamanho-1;
    while(inicio <= fim) {
        int meio = (inicio + fim)/2;
        if(vetor[meio] == valor) return meio + 1;
        if(vetor[meio] < valor) inicio = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}

void apagar(int valor) {
    int pos = buscar(valor) - 1;
    if(pos == -1) return;
    
    for(int i = pos; i < tamanho-1; i++) {
        vetor[i] = vetor[i+1];
    }
    tamanho--;
}

void mostrar() {
    if(tamanho == 0) {
        printf("Vetor vazio!\n");
        return;
    }
    
    printf("Vetor (%d): ", tamanho);
    for(int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int opcao, num, tamanho_inicial;

    do {
        printf("Tamanho do vetor (3-50): ");
        scanf("%d", &tamanho_inicial);
    } while(tamanho_inicial < 3 || tamanho_inicial > 50);

    printf("Digite %d numeros (em qualquer ordem):\n", tamanho_inicial);
    tamanho = 0;
    for(int i = 0; i < tamanho_inicial; i++) {
        scanf("%d", &num);
        adicionarOrdenado(num);
    }

    do {
        mostrarMenu();
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                mostrar();
                break;
                
            case 2:
                printf("Numero para buscar: ");
                scanf("%d", &num);
                int pos = buscar(num);
                if(pos != -1) printf("Esta na posicao %d\n", pos);
                else printf("Nao encontrado!\n");
                break;
                
            case 3:
                printf("Numero para apagar: ");
                scanf("%d", &num);
                apagar(num);
                break;
                
            case 4:
                printf("Numero para adicionar: ");
                scanf("%d", &num);
                adicionarOrdenado(num);
                break;
                
            case 5:
                printf("Saindo...\n");
                break;
                
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 5);

    return 0;
}