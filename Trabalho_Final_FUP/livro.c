#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "livro.h"

void livros_para_arquivo(livro *l, int *n)
{
   int error = 0;
   FILE *z = fopen("livros.txt", "w");
   if(z == 0){
    printf("Erro: nao foi possivel abrir o arquivo\n");
    error = 1;
   }
   if(error == 0){
    for(int i = 0; i < *n; i++){
        fprintf(z, "%d\n%s\n%s\n%d\n", l[i].num_livro, l[i].titulo, l[i].autor, l[i].matricula_aluno);
    }
   }
   fclose(z);
}

livro* le_livros_arquivo(livro *l, int *n, int *total_livros)
{
   FILE *z = fopen("livros.txt", "r");
   livro a;
   int error = 0;
    if(z == 0){
      printf("Nao foi possivel abrir o arquivo");
      error = 1;
    }
  if(error == 0){
   while(fscanf(z, "%d\n%[^\n]\n%[^\n]%d", &a.num_livro, a.titulo, a.autor, &a.matricula_aluno) == 4){
    a.data_hora_emprestimo = time(0);
    a.data_hora_devolucao = time(0) + 2592000;
    l = (livro * ) realloc(l, ( * n + 1) * sizeof(livro));    
    l[*n] = a;
    (*n)++;
    (*total_livros)++;
   }
   fclose(z);
  }
   return l;
}

livro le_livro(int *total_livros) {
  livro x;
  x.num_livro = *total_livros;
  printf("ID do Livro: %d\n", x.num_livro);
  printf("Insira o titulo do livro: ");
  scanf(" %[^\n]", x.titulo);
  printf("Insira o nome do autor do livro: ");
  scanf(" %[^\n]", x.autor);
  printf("Livro cadastrado! ");
  x.matricula_aluno = 0;
  x.data_hora_emprestimo = time(0);
  x.data_hora_devolucao = time(0) + 2592000;
  (*total_livros)++;
  return x;
}
livro * insere_livro(livro * l, int * n, livro novo) {
  l = (livro * ) realloc(l, ( * n + 1) * sizeof(livro));

  if (l == 0) {

    printf("ERRO: não foi possível inserir livro");
    return 0;
  }
  l[ * n] = novo;
  ( * n) ++;
  return l;
}
livro * remove_livro(livro * l, int * n) {
  int id_livro;
  printf("Insira o ID do livro: ");
  scanf("%d", &id_livro);
  for (int i = 0; i < * n; i++) {
    if (l[i].num_livro == id_livro) {
      l[i] = l[ * n - 1];
      l = (livro * ) realloc(l, ( * n - 1) * sizeof(livro));
      ( * n) --;
      break;
    }
    if (l == 0) {
      printf("ERRO: não foi possível inserir livro");
      return 0;
    }
    printf("Livro removido! ");
  }
    return l;
}
void listar_livro(livro * l, int * n) {
  for (int i = 0; i < * n; i++) {
    printf("ID: %d\nTitulo: %s\nAutor: %s\n", l[i].num_livro, l[i].titulo, l[i].autor);
    if (l[i].matricula_aluno != 0) {
      printf("Emprestado para: %d\n", l[i].matricula_aluno);
    } else printf("Disponivel\n");
  }
}