#include <stdio.h> 
#include <stdlib.h>

typedef struct Node {
    int senha;
    int idade;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;
 
void initializeQueue (Queue *q) {
    q->front = q->rear = NULL;
} 

int isEmpty (Queue *q) {
    return q->front == NULL;
}
 
void enqueue (Queue *q, int senha, int idade) {
    Node *newNode = (Node*) malloc (sizeof (Node));
    newNode->senha = senha;
    newNode->idade = idade;
    newNode->next = NULL;
  
    if (isEmpty (q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void dequeue (Queue *q) {
    if (!isEmpty (q)) {
        Node *temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
}

void printQueue (Queue *prioA, char fila) {
    // printf ("Fila %c: ", fila);
    // Node *current = q->front;
    // while (current != NULL) {
    //     printf ("[%d,%d]", current->senha, current->idade);
    //     current = current->next;
    //     if (current != NULL) {
	   //     printf ("->");
	   // }
    // }
    // printf ("...");
    printf("Prioritários-A: ");
    Node *current = prioA->front;
    while (current != NULL) {
        printf ("[%d,%d]", current->senha, current->idade);
        current = current->next;
        if (current != NULL) {
	        printf ("->");
        }
    }
    printf("Não-prioritários-A:");
    
    while (current != NULL) {
        printf ("[%d,%d]", current->senha, current->idade);
        current = current->next;
        if (current != NULL) {
	        printf ("->");
        }
    }
}

int main () {
    Queue prioA, naoPrioA, naoAgend; 
    initializeQueue(&prioA);
    initializeQueue(&naoPrioA);
    initializeQueue(&naoAgend);
    char acao;
    int senha, idade;
    char categoria;
    while (1) {
        scanf ("%c", &acao);
        if (acao == 'f') {
	        break;
	    }
        scanf ("%d %d %c", &senha, &idade, &categoria);
        switch (acao) {
	        case 'i': 
	            switch (categoria) {
	                case 'A':
	                    if (idade >= 60) {
	                        enqueue(&prioA, senha, idade);    
	                    } else {
	                        enqueue(&naoPrioA, senha, idade);
	                    }
	                break;
	                case 'B':
	                    enqueue(&naoAgend, senha, idade);
	                break;
	            }
	        break;
	        case 'r':
	            //
	            
	        break;
	        case 'p':
	            switch (fila) {
	                case 'A':
	                    printQueue(&filaA, 'A');
	                break;
	                case 'B':
	                    printQueue(&filaB, 'B');
	                break;
	                case 'C':
	                    printQueue(&filaC, 'C');
	                break;
	           }
	       break;
        }
    }
return 0;
}
