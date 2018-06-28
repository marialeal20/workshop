#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elemento{
	char dado;
	struct elemento * proximo;
}t_elemento;


typedef struct lista{
	t_elemento * primeiro;
	t_elemento * ultimo;
}t_lista;


typedef struct pilha{
	t_lista * l;
}t_pilha;

typedef struct fila{
	t_lista * l;
}t_fila;


///* INICIO LISTA */

t_lista * criaLista(){
   t_lista * l = (t_lista *)malloc(sizeof(t_lista));
   l->primeiro = NULL;
   l->ultimo = NULL;
   return l;
}


int estaVazia(t_lista * l){
    if(l->primeiro == NULL){
       return 1;///condição verdadeira
    }
    return 0;///condição falsa
}


void insereInicio(char valor, t_lista * l){
    t_elemento * novoprimeiro = (t_elemento *)malloc(sizeof(t_elemento));
    novoprimeiro->dado = valor;
    novoprimeiro->proximo = l->primeiro;
    l->primeiro = novoprimeiro;
    if(l->ultimo == NULL){
        l->ultimo = novoprimeiro;
    }
}


void insereFinal(char valor, t_lista * l){
   t_elemento * novoultimo = (t_elemento *)malloc(sizeof(t_elemento));
   novoultimo->dado = valor;
   novoultimo->proximo = NULL;
   if(l->primeiro == NULL){
      l->primeiro = novoultimo;
   }else{
     l->ultimo->proximo = novoultimo;
   }
   l->ultimo = novoultimo;
}

char removeInicio(t_lista * l){
    if(estaVazia(l)){
        return -1;
    }
    char tmp = l->primeiro->dado;
    t_elemento * removido = l->primeiro;
    l->primeiro = l->primeiro->proximo;
    free(removido);
    if(l->primeiro == NULL){
       l->ultimo = NULL;
    }
    return tmp;
}

///* FIM LISTA */







///* INICIO PILHA */

t_pilha * criaPilha(){
   t_pilha * p =  (t_pilha *)malloc(sizeof(t_pilha));
   p->l = criaLista();
   return p;
}

void empilhar(char valor,t_pilha * p){
  insereInicio(valor, p->l);
}


char desempilhar(t_pilha * p){
  return removeInicio(p->l);
}


int estaVaziaPilha(t_pilha * p){
    return estaVazia(p->l); ///1: Pilha vazia / 0: Pilha nao vazia
}

///* FIM PILHA */






///* INICIO FILA */

t_fila * criaFila(){
   t_fila * f =  (t_fila *)malloc(sizeof(t_fila));
   f->l = criaLista();
   return f;
}


void enfileirar(char valor, t_fila * f){
  insereFinal(valor, f->l);
}


char desenfileirar(t_fila * f){
  return removeInicio(f->l);
}


int estaVaziaFila(t_fila * f){
    return estaVazia(f->l); /// 1: fila vazia / 0: fila não vazia
}

///* FIM FILA */


///VALIDAÇÃO DA EXPRESSÃO: RETORNA 1 PRA "EXPRESSÃO VALIDA" E RETORNA 0 PARA "EXPRESSÃO NÃO VÁLIDA".
int validacao_expressao(char equacao_infixa[30]){
    t_pilha* pi;
    pi = criaPilha();
    int i=0;

    while(equacao_infixa[i] != '\0'){
    if(equacao_infixa[i] == '('){empilhar(equacao_infixa[i], pi);}
    printf("\n%c", pi->l->primeiro->dado);
    ///if(estaVaziaPilha(pi) == '0')
    if(equacao_infixa[i] == ')'){desempilhar(pi);}
       /// {if(equacao_infixa[i] == ')'){desempilhar(pi);}}
    i++;
    }
    if(estaVaziaPilha(pi)=='1'){return 1;}
    else{return 0;}
}

int main()
{
    char equacao_infixa[30];
    float equacao_posfixa;
    printf("\nTransformacao da forma infixa para posfixa.\nEntre com uma equacao infixa:\n");
    scanf("%s", equacao_infixa);
    printf("\n%d\n", validacao_expressao(equacao_infixa));
    ///printf("%f", equacao_posfixa);
    return 0;
}
