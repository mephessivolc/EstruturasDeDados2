#include <stdio.h>
#include <stdlib.h>

typedef struct reg{
  int info; // conteudo
  struct reg *filho, *irmao; // registro de filhos e irmaos
} TArvore;

TArvore * criarnovo(){
  TArvore * node = malloc(sizeof (TArvore));
  node->filho = node->irmao = NULL;

  return node;
}

TArvore * buscarInfo(TArvore * r, int info) {
  if ( r == NULL || (r->irmao == NULL && r->filho == NULL) || r->info == info)
    return r;

  TArvore * p = r->filho;
  while(p){
    TArvore * resp = buscarInfo(p, info);
    if (resp) return resp;
    p = p->irmao;
  }

  return NULL;
}

void inserir(TArvore * r, int info){
  int conteudo;
  TArvore * novo, * irmao;

  novo = criarnovo();

  printf("\nProcurar Pai: ");
  scanf("%d", &conteudo);
  irmao = buscarInfo(r, info);

  if(irmao != NULL){
    printf("\nInserir valor: ");
    scanf("%d", &conteudo);

    printf("Foi\n" );
    while (irmao != NULL)
      irmao = irmao->irmao;

    irmao->irmao = novo;
    novo->info = info;

  } else {
    printf("\n\nPai %d nao encontrado\n", conteudo);
  }


}

void main() {
  int info;
  TArvore * raiz = criarnovo();

  while (1){
    printf("\nInserir informacao: (0-nao)");
    scanf("%d", &info);

    if(info != 0) {
      inserir(raiz, info);
    } else {
      printf("Saindo\n" );
      break;
    }
  }

}
