#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "aluno.h"

void alunos_para_arquivo(aluno *v, int *n)
{
   FILE *f = fopen("alunos.txt", "w");
   for(int i = 0; i < *n; i++){
        fprintf(f, "%d\n%s\n", v[i].matricula, v[i].nome);
   }
   fclose(f);
}

aluno* le_alunos_arquivo(aluno *v, int *n, int *total_alunos)
{
   FILE *f = fopen("alunos.txt", "r");
   aluno a;
   int error = 0;
    if(f == 0){
      printf("Nao foi possivel abrir o arquivo");
      error = 1;
    }
  if(error == 0){
   while(fscanf(f, "%d\n%[^\n]\n", &a.matricula, a.nome) == 2){
    v = (aluno * ) realloc(v, ( * n + 1) * sizeof(aluno));    
    v[*n] = a;
    (*n)++;
    (*total_alunos)++;
   }
   fclose(f);
  }
   return v;
}


aluno le_aluno(int *total_alunos) {
  aluno a;
  a.matricula = *total_alunos;
  printf("Matricula : %d\n", a.matricula);
  printf("Insira o nome do aluno: ");
  scanf(" %[^\n]", a.nome);
  printf("Aluno cadastrado! ");
  (*total_alunos)++;
  return a;
}

aluno * insere_aluno(aluno * v, int * n, aluno novo) {
  v = (aluno * ) realloc(v, ( * n + 1) * sizeof(aluno));
  if (v == 0) {
    printf("Erro: Nao foi possivel alocar memoria");
    return 0;
  }
  v[ * n] = novo;

  ( * n) ++;

  return v;
}

aluno * remove_aluno(aluno * v, int * n) {
  int matricula;
  printf("Insira a matricula do aluno: ");
  scanf("%d", &matricula);
  for (int i = 0; i < * n; i++) {
    if (v[i].matricula == matricula) {
      v[i] = v[ * n - 1];
      v = (aluno * ) realloc(v, ( * n - 1) * sizeof(aluno));
      if (v == 0) {
        printf("Erro: Nao foi possivel alocar memoria");
        return 0;
      }
      printf("Aluno removido! ");
      ( * n) --;
      break;
    }
  }
  return v;
}
void listar_aluno(aluno * v, int * n) {
  for (int i = 0; i < * n; i++) {
    printf("Matricula: %d\nNome: %s\n\n ", v[i].matricula, v[i].nome);
  }
}