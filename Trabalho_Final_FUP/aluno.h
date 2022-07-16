#ifndef ALUNO_H
#define ALUNO_H

typedef struct {
  int matricula;
  char nome[50];
}
aluno;
void alunos_para_arquivo(aluno *v, int *n);
aluno* le_alunos_arquivo(aluno *v, int *n, int *total_alunos);
aluno le_aluno();
aluno * insere_aluno(aluno * v, int * n, aluno novo);
aluno * remove_aluno(aluno * v, int * n);
void listar_aluno(aluno * v, int * n);

#endif 