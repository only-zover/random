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

void inicializa(PILHA *p);
int  cheia(PILHA p);
int  vazia(PILHA p);
void imprime(PILHA p);
void push(PILHA *p, TAREFA tarefa);
TAREFA pop(PILHA *p);
void setData(DATA *d, int dia, int mes, int ano);
void setTarefa(TAREFA *t, int numero, DATA i, DATA f);
void troca(PILHA *saida, PILHA *entrada);

int main(){
    PILHA p1, p2, p3;
    TAREFA t1, t2, t3, t4;
    DATA d1, d2, d3;

    inicializa(&p1);
    inicializa(&p2);
    setData(&d1, 1, 1, 1010);
    setData(&d2, 2, 2, 2020);
    setData(&d3, 3, 3, 3030);
    setTarefa(&t1, 1, d1, d2);
    setTarefa(&t2, 2, d2, d3);
    setTarefa(&t3, 3, d3, d1);
    setTarefa(&t4, 4, d1, d2);

    push(&p1, t1);
    push(&p1, t2);
    push(&p2, t3);
    push(&p2, t4);

    imprime(p1);
    imprime(p2);

    troca(&p2, &p1);
    
    imprime(p1);
    imprime(p2);
}

void inicializa(PILHA *p){
    p->topo = -1;
}

int cheia(PILHA p){
    return(p.topo == (N-1));
}

int vazia(PILHA p){
    return(p.topo == -1);
}

void imprime(PILHA p){
    printf("Conteúdo da Pilha:\n");
    for (int i = 0; i <= p.topo; i++) {
        printf("Tarefa %d:\n", i + 1);
        printf("Número: %d\n", p.pilha[i].numero);
        printf("Data de Início: %d/%d/%d\n", p.pilha[i].diaInicio.dia, p.pilha[i].diaInicio.mes, p.pilha[i].diaInicio.ano);
        printf("Data de Fim: %d/%d/%d\n", p.pilha[i].diaFim.dia, p.pilha[i].diaFim.mes, p.pilha[i].diaFim.ano);
        printf("\n");
    }
}

void push(PILHA *p, TAREFA tarefa){
    if(!cheia(*p)){
        p->topo++;
        p->pilha[p->topo] = tarefa;
    }
}

TAREFA pop(PILHA *p){
    TAREFA tarefa_temp;
    if(!vazia(*p)){
        tarefa_temp = p->pilha[p->topo];
        p->topo--;
        return tarefa_temp;
    }
}

void setData(DATA *d, int dia, int mes, int ano) {
    d->dia = dia;
    d->mes = mes;
    d->ano = ano;
}

void setTarefa(TAREFA *t, int numero, DATA i, DATA f) {
    t->numero = numero;
    t->diaInicio = i;
    t->diaFim = f;
}

void troca(PILHA *saida, PILHA *entrada) {
    TAREFA tarefa_temp;
    if (!vazia(*saida)) {
        tarefa_temp = pop(saida);
        push(entrada, tarefa_temp);
    }
}