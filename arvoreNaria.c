#include <stdio.h>
#include <stdlib.h>

typedef struct reg{
  int info; // conteudo
  struct reg *filho, *irmao; // registro de filhos e irmaos
} TArvore;

TArvore * raiz;

TArvore * criarnovo(int info){
  TArvore * node = malloc(sizeof (TArvore));
  node->filho = node->irmao = NULL;
  node->info = info;

  return node;
}

TArvore * buscarInfo(TArvore * r, int info) {
  if (r->filho == NULL && r->irmao == NULL)
    return r;

  if (r->info == info)
    return r;

  TArvore * p = r->filho;
  while(1){
    printf("Buscando filho\n");
    TArvore * resp = buscarInfo(p, info);
    if(p->irmao != NULL)
      p = p->irmao;
    else if (p->filho != NULL)
      p = p->filho;
    else if (p->)
    p = p->irmao;
  }

  return NULL;
}

void inserir(TArvore * r){
  int conteudo;
  TArvore * novo, * ultimoIrmao, * pai;

  printf("\nProcurar Pai: ");
  scanf("%d", &conteudo);
  pai = buscarInfo(r, conteudo);

  if(pai != NULL){
    printf("\nInserir valor: ");
    scanf("%d", &conteudo);

    ultimoIrmao = pai->filho;

    while (ultimoIrmao->irmao != NULL ){
      ultimoIrmao = ultimoIrmao->irmao;
    }

    novo = criarnovo(conteudo);
    ultimoIrmao->irmao = novo;

  } else {
    printf("\n\nPai %d nao encontrado\n", conteudo);
  }

}

void listarArvore(TArvore * pointer) {
  if (pointer == NULL) return ;
  printf("%d(", pointer->info );
  TArvore * p = pointer->filho;

  while(p){
    listarArvore(p);
    p = p->irmao;
  }
  printf(")" );
}

void main() {
  int info;
  printf("\nCriando raiz\n" );
  printf("Insira valor:" );
  scanf("%d", &info );
  raiz = criarnovo(info);

  while (1){
    printf("\nInserir novas informacoes? (0-nao) ");
    scanf("%d", &info);

    if(info != 0) {
      inserir(raiz);
      listarArvore(raiz);
    } else {
      break;
    }
  }

  listarArvore(raiz);

}
