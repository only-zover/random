#include <stdio.h> 
#include <stdlib.h>

typedef struct Cliente {
    int senha;
    int idade;
    struct Cliente *prox;
} Cliente;

typedef struct {
    Cliente *frente;
    Cliente *atras;
} Fila;

void initializeQueue (Fila *f) {
    f->frente = f->atras = NULL;
}

int estaVazio (Fila *f) {
    return f->frente == NULL;
}

void enfileirar (Fila *f, int senha, int idade) {
    Cliente *novoCliente = (Cliente*) malloc (sizeof (Cliente));
    novoCliente->senha = senha;
    novoCliente->idade = idade;
    novoCliente->prox = NULL;
  
    if (estaVazio (f)) {
        f->frente = f->atras = novoCliente;
    } else {
        f->atras->prox = novoCliente;
        f->atras = novoCliente;
    }
}

Cliente* desenfileirar (Fila *f) {
    Cliente *temp = NULL;
    if (!estaVazio(f)) {
        temp = f->frente;
        f->frente = f->frente->prox;
        temp->prox = NULL; // Isso é importante para evitar que a fila inteira seja liberada quando chamamos free(temp) mais tarde
    }
    return temp;
}

void imprimirFila (Fila *prioA, Fila *prioB, Fila *prioC) {
    printf("Prioritários-A: ");
    if (estaVazio(prioA)) {
        printf("Vazia");
    }
    Cliente *cliente = prioA->frente;
    while (cliente != NULL) {
        printf ("[%d,%d]", cliente->senha, cliente->idade);
        cliente = cliente->prox;
        if (cliente != NULL) {
	        printf ("->");
        }
    }

    printf("\nNão-prioritários-A: ");
    if (estaVazio(prioB)) {
        printf("Vazia");
    }
    cliente = prioB->frente;
    while (cliente != NULL) {
        printf ("[%d,%d]", cliente->senha, cliente->idade);
        cliente = cliente->prox;
        if (cliente != NULL) {
	        printf("->");
        }
    }

    printf("\nNão agendados-B:");
    if (estaVazio(prioC)) {
        printf(" Vazia\n");
    }
    cliente = prioC->frente;
    while (cliente != NULL) {
        printf ("[%d,%d]", cliente->senha, cliente->idade);
        cliente = cliente->prox;
        if (cliente != NULL) {
	        printf ("->");
        }
    }
    printf("\n");
}

void removerImprimir(Fila* queue, char* queueName, int limit) {
    int cont = 0;
    while (!estaVazio(queue) && cont < limit) {
        Cliente* cliente = desenfileirar(queue);
        if (cliente != NULL) {
            printf("%s,%d,%d\n", queueName, cliente->senha, cliente->idade);
            free(cliente);
            cont++;
        }
    }
    if (estaVazio(queue)) {
        printf("Vazia.\n");
    }
}

int main () {
    Fila prioA, naoPrioA, naoAgend; 
    initializeQueue(&prioA);
    initializeQueue(&naoPrioA);
    initializeQueue(&naoAgend);
    char acao;
    int senha, idade;
    char categoria;
    while (1) {
        scanf ("%c %d %d %c", &acao, &senha, &idade, &categoria);
        switch (acao) {
            case 'f':
            break;
	        case 'i': 
	            switch (categoria) {
	                case 'A':
	                    if (idade >= 60) {
	                        enfileirar(&prioA, senha, idade);    
	                    } else {
	                        enfileirar(&naoPrioA, senha, idade);
	                    }
	                break;
	                case 'B':
	                    enfileirar(&naoAgend, senha, idade);
	                break;
	            }
	        break;
	        case 'r':
                removerImprimir(&prioA, "Prioritários-A: ", 4);
                removerImprimir(&naoPrioA, "Não-prioritários-A: ", 4);
                removerImprimir(&naoAgend, "Não agendados-B: ", 2);
                if (estaVazio(&prioA) && estaVazio(&naoPrioA) && estaVazio(&naoAgend)) {
                    removerImprimir(&prioA, "prioritários-A: ", 4);
                }
	        break;
	        case 'p':
	            imprimirFila(&prioA, &naoPrioA, &naoAgend);
	        break;
        }
    }
return 0;
}
