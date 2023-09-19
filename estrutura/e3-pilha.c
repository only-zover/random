#include <stdio.h>
#include <stdio.h>

#define N 100

typedef struct{
	int dia;
	int mes;
	int ano;
} DATA;
typedef struct{
	int  numero;
	DATA diaInicio;
	DATA diaFim;
} TAREFA;

typedef struct {
    TAREFA pilha[N];
    int topo;
} PILHA;

/* Altere as funções */

void inicializa(PILHA *p);
int  cheia(PILHA p);
int  vazia(PILHA p);
void imprime(PILHA p);
void push(PILHA *p, int valor);
int  pop(PILHA *p);

/*Crie funções */
/*
void setData(DATA *d, int dia, int mes, int ano);
-- define os valores de uma variável tipo data com os
   valores de dia, mes e ano
   
void setTarefa(TAREFA *t, int numero, DATA i, DATA f);
-- define os valores da tarefa.

void troca(PILHA *saida, PILHA *entrada);
-- desempilha uma tarefa da pilha de saída e empilha na pilha de entrada.
*/

int main(){
    // PILHA p1, p2, p3;
    // int temp;
    printf("Hello World!\n");
    // inicializa(&p1);
    // inicializa(&p2);
    // inicializa(&p3);

    // push(&p1,10);
    // push(&p1,20);
    // push(&p1,30);

    // push(&p2,100);
    // push(&p2,200);
    // push(&p2,300);

    //temp = pop(&p1);
    //push(&p2,temp);

    // push(&p2,pop(&p1));

    // while(!vazia(p1)) push(&p3,pop(&p1));
    // while(!vazia(p2)) push(&p3,pop(&p2));

}


void inicializa(PILHA *p){
    p->topo = -1;
}

int  cheia(PILHA p){
    return(p.topo == (N-1));
}

int  vazia(PILHA p){
    return(p.topo == -1);
}

void imprime(PILHA p){ //IMPLEMENTAR.

}

// void push(PILHA *p, int valor){
//     if(!cheia(*p)){
//         p->topo++;
//         p->pilha[p->topo] = valor;
//     }

// }
// int  pop(PILHA *p){
//     int temp;
//     if(!vazia(*p)){
//         temp = p->pilha[p->topo];
//         p->topo--;
//         return temp;
//     }else{
//         return -1;
//     }
// }
