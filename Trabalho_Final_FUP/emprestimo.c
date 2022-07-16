#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "emprestimo.h"

livro * emprestar_livro(livro * l, aluno * v, int * n_livro, int * n_aluno) {
  int matricula, id_livro;
  printf("Insira a matricula do aluno:\n");
  scanf("%d", & matricula);
  printf("Insira o ID do livro:\n");
  scanf("%d", & id_livro);
  for(int i = 0; i<*n_livro; i++){
    if(id_livro == l[i].num_livro){
      if(l[i].matricula_aluno > 0){
        printf("\nESTE LIVRO JA ESTA EMPRESTADO\n");
        return l;
      }
    }
  }
  for (int i = 0; i < * n_aluno; i++) {
    for (int j = 0; j < * n_livro; j++) {
      if (v[i].matricula == matricula && l[j].num_livro == id_livro) {
        l[j].matricula_aluno = v[i].matricula;
        l[j].data_hora_emprestimo = time(0);
        l[j].data_hora_devolucao = time(0) + 2592000;
      }
    }
  }
  return l;
}
livro * devolver_livro(livro * l, int * n_livro) {
  int id_livro;
  printf("Insira o ID do livro:\n");
  scanf("%d", & id_livro);
  for (int i = 0; i < * n_livro; i++) {
    if (l[i].num_livro == id_livro) {
      l[i].matricula_aluno = 0;
      l[i].data_hora_emprestimo = time(0);
      l[i].data_hora_devolucao = 0;
    }
  }
  return l;
}
void listar_emprestimos(livro * l, aluno * v, int * n_livro, int * n_aluno) {
  int aux;
  for (int j = 0; j < * n_livro; j++) {
    if (l[j].matricula_aluno > 0) {
      l[j].data_hora_devolucao = time(0) + 2592000;
      for (int i = 0; i < * n_aluno; i++) {
        if (v[i].matricula == l[j].matricula_aluno) {
          aux = i;
        }
      }
      printf("Livro: %s (ID: %d)\nEmprestado para matricula: %d\nNome do Aluno: %s\n", l[j].titulo, l[j].num_livro, v[aux].matricula, v[aux].nome);
      printf("Data de devolucao: %s", ctime( & l[j].data_hora_devolucao));
    }
  }
}