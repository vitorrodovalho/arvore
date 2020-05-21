#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
  int info;
  struct arvore* dir; //ponteiro para subárvore à direita (dir)
  struct arvore* esq; //ponteiro para subárvore à esquerda (esq)
} Arvore;

/* Função que cria uma árvore */
Arvore* cria_arvore(){
  return NULL;
}

/* Função que verifica se uma árvore é vazia */
int arvore_e_vazia(Arvore* t){
  /* Retorna 1 se a árvore for vazia e 0 caso contrário */
  return t == NULL;
}

/* Função que mostra a informação da árvore */
void exibe_arvore(Arvore* t){
  if(!arvore_e_vazia(t)){ /* se a árvore não for vazia... */
    printf("%d |", t->info); /* mostra a raiz */
    exibe_arvore(t->esq); /* mostra a esq (subárvore à esquerda) */
    exibe_arvore(t->dir); /* mostra a dir (subárvore à direita) */
  }
  printf(" \n");
}

/* Função que insere um dado na árvore */
void insere_elemento(Arvore** t, int info){

  if(*t == NULL){
    *t = (Arvore*)malloc(sizeof(Arvore)); /* Aloca memória para a estrutura */
    (*t)->esq = NULL; /* Subárvore à esquerda é NULL */
    (*t)->dir = NULL; /* Subárvore à direita é NULL */
    (*t)->info = info; /* Armazena a informação */
  } else {
    if(info < (*t)->info){ /* Se o número for menor então vai pra esquerda */
      insere_elemento(&(*t)->esq, info); /* Percorre pela subárvore à esquerda */
    }
    if(info > (*t)->info){ /* Se o número for maior então vai pra direita */
      insere_elemento(&(*t)->dir, info); /* Percorre pela subárvore à direita */
    }
  }
}

int main(){
  Arvore* t = cria_arvore(); /* cria uma árvore */
  
  insere_elemento(&t, 40); /* insere o elemento 40 na árvore */
  insere_elemento(&t, 50); /* insere o elemento 50 na árvore */
  insere_elemento(&t, 30); /* insere o elemento 30 na árvore */
  insere_elemento(&t, 25); /* insere o elemento 25 na árvore */
  insere_elemento(&t, 60); /* insere o elemento 10 na árvore */

  exibe_arvore(t); /* Mostra os elementos da árvore em pré-ordem */
  
  free(t); /* Libera a memória alocada pela estrutura árvore */
  
  return 0;
}